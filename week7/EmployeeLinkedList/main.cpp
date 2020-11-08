/* main.cpp - Dona Hertel
 * main file for testing
 * linear link list
 * Demos use of linked lists
 */
 
#include "employee.h"
#include "employeelist.h"

int main()
{	
  
  EmployeeList employees;
  char first[MAX_CHAR];
  char last[MAX_CHAR];
  
  Employee* emp;  // for creating employees. Note that this is a pointer to an Employee object
  cout << "No adds " << endl;
  employees.printAll();
  
  cout << endl << endl << "Adding Joanne to list" << endl;
  strcpy(first, "Joanne");
  strcpy(last, "Harrison");
  emp = new Employee(first,last,40,25.00);
  employees.addEmployee(emp);
  employees.printAll();
  
  cout << endl << endl << "Adding Frank to list " << endl;
  strcpy(first, "Frank");
  strcpy(last, "Johnson");
  emp = new Employee(first,last,35,15.50);
  employees.addEmployee(emp);
  employees.printAll();
  
  cout << endl << endl << "Adding Susan to list " << endl;
  strcpy(first, "Susan");
  strcpy(last, "MacIntyre");
  emp = new Employee(first, last, 20, 35.25);
  employees.addEmployee(emp);
  employees.printAll();
  
  cout << endl << endl << "Now find Frank's record " << endl;
  strcpy(last, "Johnson");
  emp = employees.findEmployeeByLastName(last);
  if(emp) // emp is not null
  {
	  emp->print();
  }
  else
  {
	  cout << "Couldn't find that employee" << endl;
  }
  
  cout << endl << endl << "Now find Non existent employee" << endl;
  strcpy(last, "McLarin");
  emp = employees.findEmployeeByLastName(last);
  if(emp) // emp is not null
  {
	  emp->print();
  }
  else
  {
	  cout << "Couldn't find that employee" << endl;
  }
  
  return 0;
}
