/* customer.h - Dona Hertel
 * Header file for Customer class.
 * This class is for information on
 * one customer.
 */
 
 
#include <iostream>
#include <cstring>

using namespace std;

#pragma once

class Customer {
    
    public: 
        
        // Default constructor (one with no parameters)
        Customer();
        
        // Another constructor (for adding all the info at declaration time)
        Customer(const char* fn, const char* ln, float bal);
        
        // destructor
        ~Customer();
        
        void print(); // prints all information about the customer
        void updateBalance(float amount); // adds amount to balance
        
     // these are assessors (getters)
         const char* getLastName();
         const char* getFirstName();
         float getBalance();
        
         
      // these are mutators (setters)
         void setLastName(const char* ln);
         void setFirstName(const char* fn);
         void setBalance(float bal);
         
    private:
     // These are private and cannot be accessed
    // outside the class
    
        char* lastName;
        char* firstName;
        float balance;
      
};


