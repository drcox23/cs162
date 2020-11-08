/* employee.cpp - Dona Hertel
 * Implementation file for Employee class.
 * This class is for information on
 * one employee.
 */
 
#include "employee.h"

// Default constructor (one with no parameters)
Employee::Employee()
{
	firstName = NULL;
	lastName = NULL;
    hours = 0;
    rate = 0.0;
}
        
// Another constructor (for adding all the info at declaration time
Employee::Employee(const char* fn, const char* ln, int h, float r)
{
    firstName = NULL;
    setFirstName(fn);
    lastName = NULL;
    setLastName(ln);
    hours = h;
    rate = r;	
}
 
void Employee::print()
{
	cout << "======Employee========"<< endl;
	if(firstName)
	{
        cout << "First Name: " << firstName << endl;
    }
    else
    {
		cout << "First Name: <none provided>" << endl;
	}
    if(lastName)
    {
        cout << "Last Name: " << lastName << endl;
    }
    else
    {
	    cout << "Last Name: <none provided>" << endl;
    }
    cout << "Hours Worked: " << hours << endl;
    cout << "Pay Rate: " << rate << endl;
    cout << "Gross Pay: " << getGrossPay() << endl;
}

float Employee::getGrossPay()
{
	return hours*rate;
}
        
const char* Employee::getLastName()
{
	return lastName;
}

const char* Employee::getFirstName()
{
	return firstName;
}

int Employee::getHours()
{
	return hours;
}

float Employee::getRate()
{
	
	return rate;
}
         
void Employee::setLastName(const char* ln)
{
	if(lastName)
	   delete [] lastName;
	lastName = new char[strlen(ln)+1];
	strcpy(lastName,ln);
}

void Employee::setFirstName(const char* fn)
{
    if(firstName) 
        delete [] firstName;
    firstName = new char[strlen(fn)+1];
	strcpy(firstName,fn);
}

void Employee::setHours(int h)
{
	hours = h;
}

void Employee::setRate(float r)
{
	rate = r;
}





