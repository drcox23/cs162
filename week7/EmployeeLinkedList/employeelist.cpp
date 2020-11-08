/* employeelist.cpp - Dona Hertel
 * Implementation of
 * functions for EmployeeList
 * class.
 * Maintains an linear linked list
 * of Employee objects.
 */
 
#include "employee.h"
#include "employeelist.h"

 
EmployeeList::EmployeeList()
{
	head = NULL;
}   

// This is needed to delete the linked list 
// when the employee list goes out of scope
EmployeeList::~EmployeeList()
{
	
	Node *curr = NULL;
	while(head) // head is not null
    {
        curr = head;  // set curr to head of list
 	    head = curr->next;  // move head over to next element (or make it null)
 	    // because we are not handling the deleting of the information anywhere
 	    // else, we need to delete it here.
 	    delete curr->data;
		delete curr;  // delete first element
	}
	
}    

// example of traversing a linked list. This will 
// visit each node and print out the information
void EmployeeList::printAll()
{
	if(!head) // means that the head is null so the list is empty
	{
		cout << "No employees in the list." << endl;
		return;
	}
	
	Node *current = head;
	while(current)  // means that current is NOT null and there is another node
	{
		current->data->print();  // prints the employees objects member function print()
		current = current->next;  // goes to next node in list (or becomes null)
	}
	
}

Employee* EmployeeList::findEmployeeByLastName(char* ln)
{
    Node *current = head;
	while(current)  // means that current is NOT null and there is another node
	{
		
		const char* name = current->data->getLastName();
		if(strcmp(ln, name) == 0)
		{
		    return current->data; // we have found the last name
		}
		current = current->next;  // goes to next node in list (or becomes null)
	}	
	return NULL;  // we couldn't find the last name
}

// This adds to the list in the backward direction. 
void EmployeeList::addEmployee(Employee* emp)
{  
    // create a new Node to add to the list
   Node *new_ptr = new Node;
    
   // set ptr->data to the passed in Employee object
   new_ptr->data = emp;
   
  // set the new ptr's next to head. head may be NULL but that's good
  // because it sets the next pointer to NULL too.
   new_ptr->next = head;
   head = new_ptr;  // point head to new node as it becomes the first node
   
}
