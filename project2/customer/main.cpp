/* main.cpp Dona Hertel
 * 
 * Bank Customer program
 * Demos use of classes
 * AND C-Strings.
 *  
 * this file holds the main
 * function which allows for 
 *   *  adding to an array at the end
 *   *  printing entire list of customers
 *   *  finding a customer by last name
 */
 
 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "customer.h"

using namespace std;

const int ARRAY_SIZE = 100; 


// this gets an integer from the user.
int intInput()
{
	int num;
	cin >> num;
	while(cin.fail())
	{
         cin.clear();
         cin.ignore(200,'\n');
         cout << "Not an integer. Please enter an integer. \n";
         cin >> num;
    }
    cin.ignore(200,'\n'); 
	return num;
}


// for getting input of float type
float floatInput()
{
	float num;
	cin >> num;
	while(cin.fail()) {
         cin.clear();
         cin.ignore(200,'\n');
         cout << "Not a number. Please enter a number. \n";
         cin >> num;
    }
    cin.ignore(200,'\n'); 
	return num;
}

//This prints out the main menu
void printMenu()
{
   cout << endl << "   MENU" << endl;
   cout << "__________" << endl;
   cout << "1 - read in customers" << endl;
   cout << "2 - print customers" << endl;
   cout << "3 - add to list" << endl;
   cout << "4 - find customer in list" << endl;
   cout << "5 - delete customer" << endl;
   cout << "6 - write out customers" << endl;
   cout << "7 - quit" << endl << endl;
}

// this gets a valid choice from the user
// the choice will be between a and b.
int getChoice(int a, int b)
{
	int ch;
	
	cout << "Enter choice: ";
	ch = intInput();
	cout << endl;
	while((ch < a)||(ch > b))
	{
		cout << "not a valid choice. please re-enter" << endl;
		ch = intInput();
	}
	return ch;
}

// prints out all customers
void printCustomers(Customer list[], int count)
{
    cout << endl << endl;
    if(count == 0)
    {
        cout << "---> No Customers <---" << endl;
    }
    else
    {
        cout << "------------------------------" << endl; 
        for(int i=0; i< count; i++)
        {
			list[i].print();
        }
    }
    cout << endl << endl;
}


// gets the customer info and sets it to
// the passed in object. Notice this is passed
// in as a reference parameter so we can change it.
void getCustomerInfo(Customer &cust)
{
	char lastName[MAX_STR]; 
	char firstName[MAX_STR];
	float balance;

	cout << "First Name? " << endl;
	cin.getline(firstName, MAX_STR);
	cout << "Last Name? " << endl;
	cin.getline(lastName, MAX_STR);
	cout << "Balance? (needs to be >= 0)?" << endl;
	balance = floatInput();
	while(balance < 0)
	{
		cout << "needs to be bigger than zero" << endl;
		balance = floatInput();
	}
	cust.setFirstName(firstName);
	cust.setLastName(lastName);
	cust.setBalance(balance);
}

// add a customer to the end of the list
void addCustomer(Customer list[], int &count)
{
	if(count >= ARRAY_SIZE)
    {
		cout << "no more room in list" << endl;
		return;
	}
	getCustomerInfo(list[count]);
	count++;
}

// for finding the index of a customer with the passed in
// name.  returns the index or -1 if not found
int findIndexByName(Customer list[], int count, char name[])
{
	  for(int i = 0; i < count; i++)
	  {
		  const char *listName = list[i].getLastName();
		  if(strcmp(name, listName) == 0) // has been found
		     return i;
	  }
	  return -1; // not found
}

void findCustomer(Customer list[], int count)
{
	char name[MAX_STR];
	int idx = -1;
	
	// ask for last name
	cout << "Last Name? " << endl;
	cin.getline(name, MAX_STR);
	
	// find index of customer
	idx = findIndexByName(list, count, name);
	if(idx == -1)
	{
		cout << "No customer with the last name of " 
		     << name << endl << endl;
		return;
	}
	//print out customer info
	cout << endl;
	cout << "Customer " << name << " : " << endl << endl;
	list[idx].print();
}

void readInFile(Customer list[], int &count)
{
    char line[MAX_STR];
    double balance;
    char filename[MAX_STR];
    
    cout << "name of file to read in? ";
    cin.getline(filename, MAX_STR);
    
    ifstream inFile(filename);
    
    if(!inFile.is_open())
    {
        cout << "Can't open file " << filename << endl;
        return;
    }
    
    while( inFile.getline(line, MAX_STR) )
    {
        list[count].setFirstName(line);
        
        inFile.getline(line, MAX_STR);
        list[count].setLastName(line);
        
        inFile >> balance;
        list[count].setBalance(balance);
        inFile.ignore(100,'\n');
        
        count++;
    }
    
    inFile.close();
} 

void writeToFile(Customer list[], int count)
{
    char filename[MAX_STR];
    
    cout << "name of file to write to? ";
    cin.getline(filename, MAX_STR);
    
    ofstream outFile(filename);
    
    if(!outFile.is_open())
    {
        cout << "cant open file " << filename << endl;
        return;
    }
    
    for(int i=0; i<count; i++)
    {
        outFile << list[i].getFirstName() << endl;
        outFile << list[i].getLastName() << endl;
        outFile << list[i].getBalance() << endl;
    }
    
    outFile.close();
}

void deleteCustomer(Customer list[], int &count)
{
    
    char lastName[MAX_STR];
    
    cout << "Customer's Last Name? " << endl;
    cin.getline(lastName, MAX_STR);
    
    int idx = findIndexByName(list, count, lastName);
    if(idx == -1)
    {
        cout << "Customer not found" << endl;
        return;
    }
    
    for(int i=idx; i<=count; i++)
    {
        list[i] = list[i+1];  // This is a problem with 
                              // dynamic strings without
                              // overloading the assignment operator
                              // or having a  copy constructor
    }
    
    count--;    
}

// Main function: has the array and the main menu loop
int main()
{	
	int choice;
	Customer list[ARRAY_SIZE];  
	int count = 0;
	bool quit = false;	
	
	while(!quit)
	{
		
	    printMenu();
	    choice = getChoice(1, 7);

	    switch(choice)
	    {
            case 1: readInFile(list, count);
                    break;
			case 2: printCustomers(list, count);
			        break;
			case 3: addCustomer(list, count);
			        break;
			case 4: findCustomer(list, count);
			        break;
            case 5: deleteCustomer(list, count);
                    break;
            case 6: writeToFile(list, count);
                    break;
			case 7: quit = true;
			        break;
		}
	}
    
	return 0;
}
