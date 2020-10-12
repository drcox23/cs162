/* carmain2.cpp 
 * Please don't rewrite this file
 * I will be using the exact
 * same file below when grading
 * 
 */

#include <iostream>
#include "car.h"

using namespace std;

int main()
{
    string cmake = "Honda";
    string cmodel = "Civic";
    int cyear = 2017;
	Car sedan;  // or Car sedan(); -> both call the default constructor
	Car compact(cmake, cmodel, cyear);

    // input 
    string imake;
    string imodel;
    int iyear;

    // output 
    string omake;
    string omodel;
    int oyear;
    
    //Print out values before setting them
    cout << "Sedan before initialization: " << endl;
    omake = sedan.getMake();
    cout << "Make: " << omake << endl;

    omodel = sedan.getModel();
    cout << "Model: " << omodel << endl;

    oyear = sedan.getYear();
    cout << "Year: " << oyear << endl;
    
    cout << "Compact values " << endl;
    omake = compact.getMake();
    cout << "Make: " << omake << endl;

    omodel = compact.getModel();
    cout << "Model: " << omodel << endl;

    oyear = compact.getYear();
    cout << "Year: " << oyear << endl;
    
    //set the values for sedan
    cout << "Setting values for sedan: " << endl;
    cout << "Enter make: ";
    getline(cin, imake);
    sedan.setMake(imake);

    cout << "Enter model: ";
    getline(cin, imodel);
    sedan.setModel(imodel);
    
    cout << "Enter year: ";
    cin >> iyear;
    cin.ignore(200, '\n');
    sedan.setYear(iyear);
   
    // getting the data back out
    cout << "printing values for sedan: " << endl;
    omake = sedan.getMake();
    cout << "Make: " << omake << endl;

    omodel = sedan.getModel();
    cout << "Model: " << omodel << endl;

    oyear = sedan.getYear();
    cout << "Year: " << oyear << endl;
    
    return 0;   
 }
    
  
