/* carmain3.cpp 
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
	Car sedan;
	char make1[MAX_STR] = "Honda";
	char make2[MAX_STR] = "Civic";
	Car compact(make1, make2, 2017);

    // input 
    char imake[MAX_STR];
    char imodel[MAX_STR];
    int iyear;

    // output 
    const char *omake;
    const char *omodel;
    int oyear;
    
    //Print out values before setting them
    cout << "Sedan before initialization: " << endl;
    sedan.print();
    
    cout << "Compact values " << endl;
    omake = compact.getMake();
    cout << "Make: " << omake << endl;

    omodel = compact.getModel();
    cout << "Model: " << omodel << endl;

    cout << "Year: " << compact.getYear() << endl;
    
    //set the values for sedan
    cout << "Setting values for sedan: " << endl;
    cout << "Enter make: ";
    cin.getline(imake, MAX_STR);
    sedan.setMake(imake);

    cout << "Enter model: ";
    cin.getline(imodel, MAX_STR);
    sedan.setModel(imodel);
    
    cout << "Enter year: ";
    cin >> iyear;
    cin.ignore(MAX_STR, '\n');
    sedan.setYear(iyear);
   
    // getting the data back out
    cout << "printing values for sedan: " << endl;
    omake = sedan.getMake();
    cout << "Make: " << omake << endl;

    omodel = sedan.getModel();
    cout << "Model: " << omodel << endl;

    cout << "Year: " << sedan.getYear() << endl;
    
    return 0;   
 }
    
  
