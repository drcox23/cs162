/* carmain4.cpp 
 * Please don't rewrite this file
 * I will be using the exact
 * same file below when grading
 * 
 * NEED TO DEFINE MAX_STR IN
 * YOUR CAR.H FILE!
 */

#include <iostream>
#include <cstring>
#include "car.h"

using namespace std;

int main()
{
    char make1[MAX_STR] = "Honda";
    char model1[MAX_STR] = "Civic";
    char make2[MAX_STR] = "Ford";
    char model2[MAX_STR] = "Escort";
    
	Car car1(make1, model1, 2017);
	
	// using copy constructor
	Car car2(car1);
    
    cout << "note that these should be the same" << endl;
    cout << "print car1 " << endl;
    car1.print();
    cout << "print car2 " << endl;
    car2.print();
    
    cout << "change car2's make from Honda to Ford" << endl;
    car2.setMake(make2);
    cout << "change car2's model from Civic to Escort" << endl;
    car2.setModel(model2);
    
    cout << "re-print car1" << endl;
    car1.print();
    cout << "re-print car2 (this should print a different make and model than car1)" << endl;
    car2.print();

   
    return 0;   
 }
    
  
