/* employeelist.h - Dona Hertel
 * Header for EmployeeList
 * class.
 * Maintains an linear linked list
 * of Employee objects.
 */
 
#include <iostream>
#include <cstring>
#include "employee.h"

using namespace std;

#pragma once

/* this is the info for
 * one node in the list
 */
struct Node 
{
    Employee *data;
    Node *next;	
};


class EmployeeList {
	
    public: 
        
        // Default constructor (one with no parameters)
        EmployeeList();
        // default destructor (needed to delete dynamically allocated memory
        ~EmployeeList();
        
        void printAll(); // prints all employees
        Employee* findEmployeeByLastName(char* ln); // finds employee object
                                                     // or passes back and NULL pointer
        void addEmployee(Employee* emp);
        
	private:
	   // this is the front of the linked list
	   // note that you only need one of these (not an array of them)
	   Node *head;
};


