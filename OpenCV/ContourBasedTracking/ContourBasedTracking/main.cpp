//****************************************************************************************

//  main.cpp
// -------------------------- ContourBasedTracking ------------------------------
// Created on OpenCV 3 version, if using for 4, change the header and lib path accordingly
// This application can tracks object based on the largest contour

//  Created by Ricky  on 25/06/2018.
//  Copyright © 2018 Ricky . All rights reserved.
//
//****************************************************************************************

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;

string intToString(int number){
    
        //this function has a number input and string output
        std::stringstream ss;
        ss << number;
        return ss.str();
    }

int main( int argc, char** argv )
{
    VideoCapture cap("/Users/ricky/Desktop/opencv/videos/mixColour.mov");

        if(!cap.isOpened()){
            cout<<"ERROR ACQUIRING VIDEO FEED\n";
            return -1;
        }

    while (true)
    {

            Mat firstImg;
            cap.read(firstImg);
            if (firstImg.empty()) //if not success, break loop
            {
                cout << "Cannot read a frame from video stream" << endl;
                break;
            }

            Mat grayImg;
        
            //Convert the captured frame from BGR to GRY
            cvtColor(firstImg, grayImg, COLOR_BGR2GRAY);
        
//          //>>>>>> Notes <<<<<<<<<<
//          //we can use compare() , inRange() , threshold() , adaptiveThreshold() , Canny() ,
//          //and others to create a binary image out of a grayscale or color one
//          //The function modifies the image while extracting the contours
//          //>>>>>>> Notes <<<<<<<<<<
        
        
        medianBlur(grayImg, grayImg, 19);
        threshold(grayImg,grayImg,120,255,CV_THRESH_BINARY_INV);
            Canny(grayImg, grayImg, 10, 200);
            //inRange(grayImg, Scalar(96, 96, 96), Scalar(199, 199, 199), grayImg);
        
            int largest_area = 0;
            int largest_contour_index = 0;
            Rect bounding_rect;
            vector<vector<Point>> contours; // Vector for storing contour
            vector<Vec4i> hierarchy;
        
            findContours( grayImg, contours, hierarchy,CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );
            // iterate through each contour.
            for( int i = 0; i< contours.size(); i++ )
            {
                //  Find the area of contour
                double a = contourArea( contours[i],false);
        
                if(a > largest_area){
                    largest_area = a;
                    cout << i << " area  " << a << endl;
        
                    // Store the index of largest contour
                    largest_contour_index = i;
        
                    // bounding rectangle for biggest contour
                    bounding_rect = boundingRect(contours[i]);
                }
            }
        
           //color of the contour
            Scalar color( 255,255,255);
        
           //Draw rectangle on the biggest contour
            rectangle(firstImg, bounding_rect,  Scalar(0,255,0) ,2 ,8, 0);
        
        int xpos = bounding_rect.x + bounding_rect.width/2;
        int ypos = bounding_rect.y + bounding_rect.height/2;
        
        //write the position of the object to the screen
            putText(firstImg,"Tracked object coordinates (" + intToString(xpos)+","+intToString(ypos)+")",Point(xpos,ypos),1,1,Scalar(255,0,0),2);
        
//            namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
//            imshow( "Display window", src );
//            waitKey(0);
//            return 0;
        
        
            // show image
            imshow("Original", firstImg); //show the original image
            imshow("median", grayImg); //show the threshold image

        
            waitKey(10);

    }

    return 0;
}




