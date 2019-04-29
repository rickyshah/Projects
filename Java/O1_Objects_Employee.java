
/*****************************************************************************************
 * OBJECTS - DECLARATION AND INITIALISATION
 ****************************************************************************************/

// system built package
package o2_classAndobjects;

// create class
public class O11_Objects_Employee {

/*........................................................................................
 * OBJECT is an instance(copy) of a class. It uses the DATA(variable of any data type) 
 * and FUNCTION of a class. THE same data and functions can be used by multiple objects
 * as shown below
 .......................................................................................*/
	
	// main function
	public static void main(String[] args) {

///*........................................................................................
// * OPTION 1 - CREATE OBJECT
// .......................................................................................*/
//
//		// declare mutiple objects
//		O10_Class_Employee Alex, Sam, Tim;
//		
//		// initialise objects
//		Alex = new O10_Class_Employee();
//		Sam = new O10_Class_Employee();
//		Tim = new O10_Class_Employee();
		
/*........................................................................................
 * OPTION 2 - CREATE OBJECT
 .......................................................................................*/
		
		// declare and initialise objects at the same time
		O10_Class_Employee Alex = new O10_Class_Employee();
		O10_Class_Employee Sam = new O10_Class_Employee();
		O10_Class_Employee Tim = new O10_Class_Employee();
		
		// call data and functions from class 'O10_Class_Employee'
		// assign value to salary and bonus for alex
		Alex.emplSalary = 5000;
		Alex.emplBonus = 200;
		Alex.calculateFinalSalary();
		
	
		// Similarly, object Sam and Tim can use data and functions of 
		// class 'O10_Class_Employee' to calculate the final salary
		Sam.emplSalary = 5000;
		Sam.emplBonus = 200;
		Sam.calculateFinalSalary();
		
		Tim.emplSalary = 5000;
		Tim.emplBonus = 200;
		Tim.calculateFinalSalary();


	}

}
