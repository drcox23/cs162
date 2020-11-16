/* customerlist.cpp - Dona Hertel
 * Implementation of
 * functions for CustomerList
 * class.
 * Maintains an linear linked list
 * of Customer objects.
 */
 
#include "customer.h"
#include "customerlist.h"

 
CustomerList::CustomerList()
{
    head = nullptr;
}   

// This is needed to delete the linked list 
// when the customer list goes out of scope
CustomerList::~CustomerList()
{
    if(!head) // head is nullptr and so list is empty
    {
        return; //nothing to delete
    }
    
    Node *curr = head;
    while(head) // head is not nullptr
    {
        curr = head;  // set curr to head of list
        head = curr->next;  // move head over to next node (or make it nullptr)
        delete curr->data;  // delete the data inside the node
        delete curr;  // delete node
    }
    
}    

// example of traversing a linked list. This will 
// visit each node and print out the information
void CustomerList::printAll()
{
    if(!head) // means that the head is nullptr so the list is empty
    {
        cout << "No customers in the list." << endl;
        return;
    }
    
    Node *current = head;
    while(current)  // means that current is NOT nullptr and there is another node
    {
        current->data->print();  // prints the customer objects member function print()
        current = current->next;  // goes to next node in list (or becomes nullptr)
    }
    
}

// This adds to the list in sorted order.
void CustomerList::addCustomer(const char* first, const char* last, int balance)
{
    // First, create a new object Customer and put in the info
    // for this customer
   Customer *d = new Customer(first,last,balance);
    
    // now create a new Node to add to the list
   Node *new_ptr = new Node;
    
   // set ptr->data to the new Customer object
   new_ptr->data = d;
   
   // set the next pointer to nullptr so we can stop when we
   // reach the end of the list when traversing the list
   new_ptr->next = nullptr;
    
   if(!head) // if head is nullptr, this is the first node  
   {
       // so just point head to this node and we're done
       head = new_ptr;
   }
   else  // here we have something in front of the list already
   {
   
      // need to find where to insert it
      Node *current = head; // start at the head.
      Node *previous = nullptr;
      
      while(current)
      {
          const char* thisLast = current->data->getLastName();
          if(strcmp(thisLast, last) > 0)
          {
               new_ptr->next = current;
               if(previous) {
                   previous->next = new_ptr; 
               }
               else // insert at head of list
               {
                   head = new_ptr; // move head to point to new pointer 
               }
               return;    
          }
          previous = current;
          current = current->next;
      }
      // if the current is nullptr then we are at the end
      // of the list and the new node is larger than all
      // nodes. So add it to the end (which is previous ptr)
      previous->next = new_ptr;
   }
   
}

void CustomerList::deleteCustomer(const char* last)
{
    if(!head)
    {
        cout << "list is empty!"<< endl;
        return;
    }
    
    // now we have to find the node in the list
    Node *current = head;// start at the head
    Node *previous = NULL; // just set to nullptr 
    while(current)
    {
        const char* thisLast = current->data->getLastName();
        if(strcmp(thisLast,last) == 0)
        {
            if(!previous) // previous is null. Head of List
            {
               head = head->next;  // move the head over to the next pointer
            }
            else // previous is not null. So deleting middle or end
            {
                previous->next = current->next;
            }
            delete current->data; // delete the data
            delete current;  // delete the node 
            return; //we are done
        }
        
        previous = current;
        current = current->next;    
    }
    
    // if we are here, the deleted node couldn't be found
    cout << "no name found." << endl;   
    
}

Customer * CustomerList::findCustomer(const char* last)
{
    if(!head)
    {
        cout << "no customers in list" << endl;
        return nullptr;
    }
    const char * thisLast;
    // start at the head node
    Node * current = head;
    while(current)
    {
        thisLast = current->data->getLastName();
        if(strcmp(thisLast, last) == 0)
        {
            // we've found the customer, so return the data
            return current->data;   
        }
        current = current->next;  // move to next node  
    }
    
    cout << "Cant find customer" << endl;
    return nullptr;
}

