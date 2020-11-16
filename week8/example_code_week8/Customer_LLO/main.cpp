/* main.cpp - Dona Hertel
 * main file for testing
 * an orderd linear link list
 * Adds customers and deletes 
 * them.
 */
 
#include "customer.h"
#include "customerlist.h"

int main()
{   
  
  CustomerList customers;
  cout << "No adds " << endl;
  customers.printAll();
  
  cout << endl << endl << "Adding Susan to list " << endl;
  const char first3[] = "Susan";
  const char last3[] = "MacIntyre";
  customers.addCustomer(first3,last3,5530);
  customers.printAll();
 
  const char first2[] = "Frank";
  const char last2[] = "Johnson";
  cout << endl << endl << "Adding Frank to list " << endl;
  customers.addCustomer(first2,last2,500);
  customers.printAll();
  
  const char first1[] = "Joanne";
  const char last1[] = "Harrison";
  cout << endl << endl << "Adding Joanne to list" << endl;
  customers.addCustomer(first1,last1,10000);
  customers.printAll();
  
  const char first5[] = "Mark";
  const char last5[] = "Zeno";
  cout << endl << endl << "Adding Mark to the list" << endl;
  customers.addCustomer(first5,last5,3456);
  customers.printAll();
  
  const char first6[] = "Nancy";
  const char last6[] = "Newman";
  cout << endl << endl << "Adding Nancy to the list" << endl;
  customers.addCustomer(first6, last6,3456);
  customers.printAll();
  
  cout << endl << endl << "Finding Frank and printing his info" << endl;
  Customer *frank = customers.findCustomer(last2);
  if(!frank)
  {
      cout << "we can't find frank" <<endl;
  }
  else
  {
      frank->print();
  }
  
  const char last8[] = "Newman";
  cout << endl << endl << "Finding Nancy and changing her balance to 2330" << endl;
  Customer *newman = customers.findCustomer(last8);
  if(!newman)
  {
      cout << "we can't find Newman" <<endl;
  }
  else
  {
      newman->setBalance(2330);
      newman->print();
  }
  
  
  cout << endl << endl << "Deleting Frank: " << endl;
  customers.deleteCustomer(last2);
  customers.printAll();
  
  cout << endl << endl << "Deleting Nancy " << endl;
  customers.deleteCustomer(last6);
  
  cout << endl << endl << "Deleting Susan " << endl;
  customers.deleteCustomer(last3);
  customers.printAll();
  
  cout << endl << endl << "Deleting Joanne" << endl;
  customers.deleteCustomer(last1);
  customers.printAll();
  
  return 0;
}
