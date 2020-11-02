/* carmain5.cpp 
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
	char make[MAX_STR] = "Honda";
	char model[MAX_STR] = "Civic";
	
	Car car1(make, model, 2017);
	Car car2;
    
    cout << "print car1 " << endl;
    car1.print();
    cout << "print car2 " << endl;
    car2.print();
    
    cout << "Now doing car2 = car1 " << endl;
    car2 = car1;
    
    cout << "print car1 " << endl;
    car1.print();
    cout << "print car2 " << endl;
    car2.print();
    
    cout << "change car2's model from Honda to Ford" << endl;
    char make2[MAX_STR] = "Ford";
    car2.setMake(make2);
    
    cout << "re-print car1" << endl;
    car1.print();
    cout << "re-print car2 (this should print a different make than car1)" << endl;
    car2.print();

   
    return 0;   
 }
    
  
