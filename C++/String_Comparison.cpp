
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <valarray>
#include <numeric>


//using namespace std;


int main(int argc, char** argv) {
    
    std::string stringOne = "Ab CD DE cc";
    std::string stringTwo = "AbCD";
    
    // sstream spits(throw out) each string of a variable given inside bracket
    std::stringstream breakStringOne(stringOne);
    
    // character(empty space) that will be used as condition to break the string 'stringOne'
    char breakString = ' ';
    
    // temporary variable to hold each string spit by stringstream 'breakStringOne'
    std::string splitStringHolder;
    
    // vector to store all spit strings all together
    std::vector<std::string> spitStringVector;
    
    // use 'while loop' for condition like while there is a string to spit 
    // out in string 'stringOne' using stringstream, continue the loop 
    
    while(getline(breakStringOne, splitStringHolder, breakString)){
        
        // add the spit string temporary kept in 'splitStringHolder' to the vector
        spitStringVector.push_back(splitStringHolder);
    }
    
    // print each item of vector using for loop and giving vector size 
    for(int i = 0; i < spitStringVector.size(); i++){
        if (stringTwo.find(spitStringVector[i]) == std::string::npos){
            std::cout << "False" << "\n";
        }else{
            std::cout << "True" << "\n";
        }
    }
    /****************************************************************************
    In above example, we use find function combined with npos(no position) to 
    check that each string broken by for loop of the vector 'splitStringVector' 
    at index postion i (spitStringVector[i]) has a postion rather than 
    no postion (npos) in the other strings. In other words whether each string 
    from the vector is contained in the string 'stringTwo but if it is 
     * npos( has no position) or not found then it is false.
    For instance: in first iteration, the string at position [i] is 'Ab', this 
    will be checked whether it is in string 'stringTwo' which is true so it will
    print 'True' if the result of this is equal to no position (npos) then it will
    print 'False'.
 
    In another way, if I have a string "AAA" and I look for "B" within it, 
    the result of that is npos meaning that the string "B" has no position 
    inside of the string "AAA": the position of "B" within "AAA" is no position.
    *****************************************************************************/
    
    return 0;
}

