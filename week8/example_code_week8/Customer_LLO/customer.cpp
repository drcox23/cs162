/* customer.cpp - Dona Hertel
 * Implementation file for Customer class.
 * This class is for information on
 * one customer.
 */
 
#include "customer.h"

// Default constructor (one with no parameters)

Customer::Customer()
{
    firstName = NULL;
    lastName = NULL;
    balance = 0.0;
}
// Another constructor (for adding all the info at declaration time
Customer::Customer(const char* fn, const char* ln, float bal)
{
    firstName = NULL;
    lastName = NULL;
    setFirstName(fn);
    setLastName(ln);
    setBalance(bal);    
}

Customer::~Customer()
{
    if(firstName) delete [] firstName;
    if(lastName) delete [] lastName;
}
 
void Customer::print()
{
    cout << "======CUSTOMER========"<< endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Balance: " << balance << endl;
}

void Customer::updateBalance(float amount)
{
    balance += amount;
    if(balance < 0)
    {
        cout << "WARNING: Balance is negative!" << endl;
    }
    
}
        
const char* Customer::getLastName()
{
    return lastName;
    
}

const char* Customer::getFirstName()
{
    
    return firstName;
}

float Customer::getBalance()
{
    
    return balance;
}
         
void Customer::setLastName(const char* ln)
{
    // need to delete any previous name
    if (lastName) delete lastName;
    // allocate new memory to fit string (plus one for null character)
    lastName = new char[strlen(ln)+1];
    // copy temp into field
    strcpy(lastName, ln);
}

void Customer::setFirstName(const char* fn)
{
    // need to delete any previous name
    if (firstName) delete firstName;
    // allocate new memory to fit string (plus one for null character)
    firstName = new char[strlen(fn)+1];
    // copy temp into field
    strcpy(firstName, fn);
}

void Customer::setBalance(float bal)
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


