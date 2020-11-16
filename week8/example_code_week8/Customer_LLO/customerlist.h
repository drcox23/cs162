/* customerlist.h - Dona Hertel
 * Header for CustomerList
 * class.
 * Maintains an linear linked list
 * of Customer objects.
 */
 
 
#include <iostream>
#include <cstring>
#include "customer.h"

using namespace std;

#pragma once

/* this is the info for
 * one node in the list
 */
 
 
struct Node 
{
    Customer *data;
    Node *next; 
};


class CustomerList {
    
    public: 
        
        // Default constructor (one with no parameters)
        CustomerList();
        // default destructor (needed to delete dynamically allocated memory
        ~CustomerList();
        
        void printAll(); // prints all customers
        void addCustomer(const char* first, const char* last, int balance);
        void deleteCustomer(const char* last);
        Customer * findCustomer(const char* last);
        
    private:
       // this is the front of the linked list
       // note that you only need one of these (not an array of them)
       Node *head;
};


