
/*********************************************************************************
 * POINTERS - POINTS(GIVES)ADDRESS AND VALUE OF A VARIABLE IN A MEMORY LOCATION 
 ********************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <valarray>
#include <numeric>

using namespace std;


//int main(int argc, char** argv) {
//   
//    // declare and initialised an integer
//    int age = 25;
//    
//    // declare and initialise a pointer to reference above integer
//    // A Pointer stores an address of the variable in memory
//    // You declare a pointer to be of the same type as the data 
//    // type to which it points
//    // If you are storing the address of an int then the 
//    // pointer is an int
//    // When you declare a pointer give it a null value
//    int* pAge = NULL;
//    
//    // The 'reference(&)' operator returns the address for a 
//    // variable that can be stored in a pointer
//    pAge = &age;
//    
//    // Print the variable address in memory location
//    std::cout << "Address : " << pAge << "\n";
//    
//    // Get the value at that address with the 'dereference(*)' operator
//    std::cout << "Value at Address : " << *pAge << "\n";
//
///*--------------------------------------------------------------------------------
// * MORE EXAMPLE 
// -------------------------------------------------------------------------------*/
//    string name = "tom";
//    string* ptrName = NULL;
//    
//    ptrName = &name;
//    
//    std::cout << "Address: " << ptrName << "\n";
//    std::cout << "Value: " << *ptrName << "\n";
//return 0;
//}



///*********************************************************************************
// * POINTERS - ARRAY 
// ********************************************************************************/
//int main(int argc, char** argv) {    
//    // We can create a pointer to an array and cycle through
//    // the data with ++ and --
//    int intArray[] = {1,2,3,4};
///*--------------------------------------------------------------------------------
// * For assigning value of an array to the pointer, there is no need to 
// * put '&' symbol in front of array
// -------------------------------------------------------------------------------*/
//    int* pIntArray = intArray; // '&' symbol is not used
//    
//    // print address location of the first item in an array using pointer
//    // again no need of '&' symbol to access/print address of array using pointer 
//    std::cout << "Address of 1st pointer is: " << pIntArray << "\n";
//    
//    // print the value of the first item in an array using pointer
//    std::cout << "Value of 1st pointer is: " << *pIntArray << "\n";
//    
//    // '++' will iterate to the next array item
//    // this will be required to print the second array address and value        
//    pIntArray++;
//    
//    // '--' will iterate to the previous array item
//    // pIntArray--;
//    
//    
//    // print address location of the second item in an array using pointer
//    std::cout << "Address of 2nd pointer is: " << pIntArray << "\n";
//    
//    // print the value of the first item in an array using pointer
//    std::cout << "Value of 2nd pointer is: " << *pIntArray << "\n";
//    
//  
//    return 0;
//}


/*********************************************************************************
 * POINTERS - change value of a variable using pointers in a functions 
 ********************************************************************************/

// create a function 'newTemp' to change value of a variable inside the main 
// function using a pointer '*pTemp'
// pointer '*pTemp' will access the address value of the arguments (variable) 
// that is passed with the function
// then the value of the variable inside the main function will be replaced
// by the value stored in the function, i,e "Hot"
void newTemp(string* pTemp){
        *pTemp = "Hot";
    }

// main function 
int main(int argc, char** argv) {
    
    string temp = "cold";
    
    std::cout << "The temperature was: " << temp << "\n";
    
    // the function 'newTemp' has been passed the variable '&temp' as an argument
    // the pointer reference(&) operator can access the location of the 'temp' 
    // then the function takes the argument and replaces the variable 'temp' value 
    // with the value stored inside the 'newTemp' function. 
    // It can do so because as soon as the function has the address
    // of the variable, it can then access the value using 'dereference(*)'
    // operators as explained above in pointer section
    newTemp(&temp);
    std::cout << "The new temperature is: " << temp << "\n";
   
    return 0;
}
