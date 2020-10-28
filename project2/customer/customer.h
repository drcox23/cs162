/* customer.h Dona Hertel
 * 
 * Class definition for Customer.
 * Customer holds information for
 * one customer of a bank. A customer
 * has a first name, last name and 
 * balance.
 * 
 */
 
#include <iostream>

using namespace std;

#pragma once

const int MAX_STR = 250;  // needed in main.cpp for static C-Strings

class Customer {
	
    public: 
    // These are public and can be accessed
    // outside the class
        
        // Default constructor (one with no parameters)
        Customer();
        
        // destructor
        ~Customer();
        
        // Another constructor (for adding all the info at declaration time)
        Customer(const char fn[], const char ln[], const float bal);
        
        void print(); // prints all information about the customer
        
     // these are assessors (getters)
         const char * getLastName();
         const char * getFirstName();
         const float getBalance();
         
      // these are mutators (setters)
         void setLastName(const char ln[]);
         void setFirstName(const char fn[]);
         void setBalance(const float bal);
         
	private:
	 // These are private and cannot be accessed
	// outside the class
	    char* lastName;
	    char* firstName;
	    float balance;
	    
};


