//****************************************************************************************

//  main.cpp
// -------------------------- ColourBasedTracking ------------------------------
// Created on OpenCV 3 version, if using for 4, change the header and lib path accordingly
// This application can track any colour object
// To use the app, run the app first, then using trackbar, find the threshold for the object
// Then it will automatically starts tracking
// Below the trackbar values is set for orange colour

//  Created by Ricky  on 25/06/2018.
//  Copyright © 2018 Ricky . All rights reserved.
//
//****************************************************************************************
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

//#include <cstdio>
//#include <sstream>
//#include <string>
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv/cv.h>
//#include "opencv2/core.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/imgproc.hpp"
//#include <vector>

using namespace cv;
using namespace std;

//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;

string intToString(int number){
    
    stringstream ss;
    ss << number;
    return ss.str();
}

//use openCV drawing functions to draw crosshairs on the tracked image!
void drawObject(int posX, int posY,Mat &frame){
    
    //added 'if' and 'else' statements to prevent
    //memory errors from writing off the screen (ie. (-25,-25) is not within the window!)
    
    circle(frame,Point(posX,posY),20,Scalar(0,255,0),2);
    if(posY-25>0)
        line(frame,Point(posX,posY),Point(posX,posY-25),Scalar(0,255,0),2);
    else line(frame,Point(posX,posY),Point(posX,0),Scalar(0,255,0),2);
    if(posY+25<FRAME_HEIGHT)
        line(frame,Point(posX,posY),Point(posX,posY+25),Scalar(0,255,0),2);
    else line(frame,Point(posX,posY),Point(posX,FRAME_HEIGHT),Scalar(0,255,0),2);
    if(posX-25>0)
        line(frame,Point(posX,posY),Point(posX-25,posY),Scalar(0,255,0),2);
    else line(frame,Point(posX,posY),Point(0,posY),Scalar(0,255,0),2);
    if(posX+25<FRAME_WIDTH)
        line(frame,Point(posX,posY),Point(posX+25,posY),Scalar(0,255,0),2);
    else line(frame,Point(posX,posY),Point(FRAME_WIDTH,posY),Scalar(0,255,0),2);
    
    putText(frame,intToString(posX)+","+intToString(posY),Point(posX,posY+30),1,1,Scalar(0,255,0),2);
    
}



int main( int argc, char** argv )
{
    //capture the video from webcam/ or read the video file
    VideoCapture cap(0); // For file give video file path in quotes "usr/filepath"
    
    if ( !cap.isOpened() )  // if not success, exit program
    {
        cout << "Cannot open the web cam" << endl;
        return -1;
    }
    
    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"
    
    
    int LowH = 0;
    int HighH = 85;
    
    int LowS = 0;
    int HighS = 255;
    
    int LowV = 130;
    int HighV = 255;

    
    //Create trackbars in "Control" window
    createTrackbar("Low Hue", "Control", &LowH, 179); //Hue (0 - 179)
    createTrackbar("High Hue", "Control", &HighH, 179);
    
    createTrackbar("Low Sat", "Control", &LowS, 255); //Saturation (0 - 255)
    createTrackbar("High Sat", "Control", &HighS, 255);
    
    createTrackbar("Low Value", "Control", &LowV, 255);//Value (0 - 255)
    createTrackbar("High Value", "Control", &HighV, 255);
    
    int iLastX = -1;
    int iLastY = -1;
    
    //Capture a temporary image from the camera
    Mat imgTmp;
    cap.read(imgTmp);
    
    //Create a black image with the size as the camera output
    Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );;
    
    
    while (true)
    {
        Mat imgOriginal;
        
        bool bSuccess = cap.read(imgOriginal); // read a new frame from video
        
        
        
        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }
        
        Mat imgHSV;
        
        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
        
        Mat imgThresholded;
        
        //object segmentation using inRange function, Threshold image
        inRange(imgHSV, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), imgThresholded);
        
        //morphological opening (removes small objects from the foreground)
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(2, 2)) );
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(2, 2)) );

        //morphological closing (removes small holes from the foreground)
        dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(2, 2)) );
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(2, 2)) );

        
        //Calculate the center of the object position using the Moments funct from the thresholded image
        //calculate 1st order spatial moments around x-axis (which is represented as dM10)
        //and y-axis (dM01)
        //and the 0th order central moments of the binary image.
        Moments oMoments = moments(imgThresholded);
        
        double dM01 = oMoments.m01; //Y coordinate of the position of the center of the object  =  1st order spatial moment around y-axis / 0th order central moment
        
        double dM10 = oMoments.m10; //X coordinate of the position of the center of the object  =  1st order spatial moment around x-axis /  0th order central moment
        
        double dArea = oMoments.m00;
        
        // if the area <= 10000, I consider that the there are no object in the image
        //and it's because of the noise, the area is not zero
                if (dArea > 5000)
                {
        //calculate the position of the ball
        int posX = dM10 / dArea;
        int posY = dM01 / dArea;
        
        if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
        {
            //Draw a red line from the previous point to the current point
            // line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
            
            putText(imgOriginal,"Tracking Object", Point(0,50),2,1,Scalar(0,255,0),2);
            
            //draw a crosshairs circle displaying coordinates using drawObject function created above
            drawObject(posX,posY, imgOriginal);
        }
        
        iLastX = posX;
        iLastY = posY;
                }
        
        imshow("Thresholded Image", imgThresholded); //show the thresholded image
        
        imgOriginal = imgOriginal + imgLines;
        imshow("Original", imgOriginal); //show the original image
        
        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }
    
    return 0;
}
