// Douglas Cox
// CS 162
// main file for this program which allows users to generate a list of cars

#include <iostream>
#include <cstring>
#include "list.h"

int main()
{
  int selector;

  List list;

  do
  {
    cout << "== Please select an option ==" << endl
         << "1. print all cars" << endl
         << "2. add a car" << endl
         << "3. delete a car" << endl
         << "4. quit a program" << endl;

    cin >> selector;
    // input validation
    while (cin.fail() || selector > 4 || selector < 1)
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Please enter a valid number between 1 and 3" << endl;
      cin >> selector;
    }
    cin.ignore(100, '\n');

    if (selector == 1)
    {
      list.printList();
    }
    else if (selector == 2)
    {
      char imake[MAX_STR], imodel[MAX_STR];
      int iyear;

      cout << "Enter Make: ";
      cin >> imake;
      cout << "Enter Model: ";
      cin >> imodel;
      cout << "Enter Year: ";
      cin >> iyear;

      list.addCar(imake, imodel, iyear);
    }
    else if (selector == 3)
    {
      list.deleteCar();
    }

  } while (selector != 4);

  cout << "Thanks for using our program. The program will now close!" << endl;

  return 0;
}