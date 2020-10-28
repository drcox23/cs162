/* customer.h Dona Hertel
 * 
 * implementation file for Customer.
 * Customer holds information for
 * one customer of a bank. A customer
 * has a first name, last name and 
 * balance.
 * 
 */

#include <cstring>
#include "customer.h"

const char notSet[] = "<not set>";  // value for an unset name

// Default constructor (one with no parameters)
Customer::Customer()
{
    firstName = NULL;
    setFirstName(notSet);
    
	lastName = NULL;
	setLastName(notSet);
    
    balance = 0;
}
        
// Another constructor (for adding all the 
// info at declaration time
Customer::Customer(const char *fn, const char *ln, const float bal)
{
    firstName = NULL;
    setFirstName(fn);
    lastName = NULL;
    setLastName(ln);
    balance = bal;	
}

// this is the one and only destructor
// need to free up the cstring space
Customer::~Customer()
{
	delete [] firstName;
	delete [] lastName;
}
 
void Customer::print()
{
	cout << "======CUSTOMER======" << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Balance: " << balance << endl;
}

        
const char * Customer::getLastName()
{
	return lastName;
	
}

const char * Customer::getFirstName()
{
	return firstName;
}

const float Customer::getBalance()
{
	
	return balance;
}
         
void Customer::setLastName(const char ln[])
{
    if(lastName != NULL)
	    delete lastName;  // delete old space
	lastName = new char[strlen(ln)+1]; // re-create space
	strcpy(lastName, ln); // copy new value into new space
}

void Customer::setFirstName(const char fn[])
{
    if(firstName != NULL)
	    delete firstName;
	firstName = new char[strlen(fn)+1];
	strcpy(firstName, fn);
}

void Customer::setBalance(const float bal)
{
	// cant set balance to 
	// a negative number.
    if(bal < 0)
    {
		cout << "Cant set balance to a negative number!" << endl;
		return;
	}
        
	balance = bal;
}
