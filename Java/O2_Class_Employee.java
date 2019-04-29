
/*****************************************************************************************
 * CLASS - DECLARATION AND INITIALISATION
 ****************************************************************************************/

// system pre-built package
package o2_classAndobjects;

/*........................................................................................
 * Class is a TEMPLATE/BLUEPRINT, which consists of DATA(variable of any data type) and 
 * FUNCTION. THE data and functions can be used in multiple places by multiple OBJECTS
 * If the class access specifier is public, it can be called by objects in other class
 .......................................................................................*/

// create class  
public class O10_Class_Employee {
	
	// declare variable, a data to hold employee salary details
	int emplSalary;
	int emplBonus;
	
	// create a function to calculate the total salary payable
	void calculateFinalSalary(){
		
		int emplFinalSalary = emplSalary + emplBonus;
		System.out.println("Final salary is: " + emplFinalSalary);
	}

}

/*****************************************************************************************
 * Notes: ONLY class with data and functions are created here
 * There is no main function here, the data and functions of this class will be 
 * called by objects of another class(11_Objects_Employee)
 ****************************************************************************************/

