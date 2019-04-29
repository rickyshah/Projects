
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

// ------------ RANGE FUNCTION FOR SOLVING PROBLEM BELOW -----------------------
std::vector<int> Range(int start, int max, 
        int step){
    
    // Every while statement needs an index 
    // to start with
    int i = start;
    
    // Will hold returning value in this vector
    std::vector<int> range;
    
    // Make sure we don't go past max value
    while(i <= max){
        
        // Add value to the vector
        range.push_back(i);
        
        // Increment the required amount
        i += step;
    }
    
    return range;
    
}
 
int main(int argc, char** argv) {
    
// ----- PROBLEM DRAW A PINE TREE -----
// For this problem I want you to draw a pine 
// tree after asking the user for the number 
// of rows. Here is the sample program
 
/*
 How tall is the tree : 5
    #
   ###
  #####
 #######
#########
    #
 */
/*********************************************************************************
 * SOLUTION 1: USING FOR LOOP AND WITHOUT USING RANGE FUNCTION WE CREATED 
*********************************************************************************/
    int usrInput;
    std::cout << "How many line pine trees?" << "\n";

    std::cin >> usrInput;
    

    std::string space = "";
    std::string hash = "#";
    
    
    int baseHashPosition = usrInput ;
    std::string baseHashSpace = "";
    
    while(usrInput != 0){
        // iterate until i is equal or less than user input
        // and on every iteration concatenate empty space to variable 'space'
        // so when the first time for loop completes, it will produce same
        // number of spaces as user input, but then the number of spaces decrease
        // every time as the user input is been decreased below by one
        // the for loop keeps on running until the while loop completes
        for(int i = 1; i<= usrInput; i++){
            std::cout << space + " ";   
        } 
        
        // print variable 'hash' after one complete for loop, the first time
        // it will just print one, as that is the starting value 
        // then the hash variable is added by two on every while loop iteration
        // and the user input is decreased by one 
        std::cout << hash << "\n";
        hash += "##";
        usrInput--;
        
        // if the user input becomes 0 or less, then break the while loop 
        if (usrInput <= 0) 
            
            break;       
    }
    
    // this for loop is needed to put the final one 'hash' to the tree at the
    // bottom, we use the user input entered at very first time by user to 
    // place the hash in combination with space using the same concept as above 
    for(int i = 1; i <= baseHashPosition; i++){
            baseHashSpace = baseHashSpace + " ";   
        }   
    std::cout << baseHashSpace + "#";
 
    
///*********************************************************************************
// * SOLUTION 2: USING RANGE FUNCTION WE CREATED 
//*********************************************************************************/
//
//std::cout << "How tall is the tree : ";
// 
//// The top of the tree starts with 1 hash
//int treeHeight = 0, spaces = 0, hashes = 1,
//        stumpSpaces = 0; 
// 
//std::cin >> treeHeight;
// 
//// Starting spaces = treeHeight - 1
//spaces = treeHeight - 1;
// 
//// Spaces before stump = tree height - 1
//stumpSpaces = treeHeight - 1;
// 
//// while there are more rows to print keep going
//while(treeHeight != 0){
//    
//    // Print spaces before hashes
//    for(auto x: Range(1, spaces, 1))
//        std::cout << " ";
//    
//    // Print the hashes
//    for(auto x: Range(1, hashes, 1))
//        std::cout << "#";
//    
//    // Newline after each row
//    std::cout << "\n";
//    
//    // Spaces decremented by 1 each time
//    spaces -= 1;
//    
//    // Hashes incremented by 2 each time
//    hashes += 2;
//    
//    // Decrement treeHeight so loop ends
//    treeHeight -= 1;
//    
//}
// 
//// Print spaces before stump
//for(auto x: Range(1, stumpSpaces, 1))
//        std::cout << " ";
// 
//// Print stump
//std::cout << "#";
    
    return 0;
}

