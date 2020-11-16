// Douglas Cox
// CS 162
// main file for this program which allows users to generate a list of cars

/* Memory Leak output:
==74483== 
==74483== HEAP SUMMARY:
==74483==     in use at exit: 0 bytes in 0 blocks
==74483==   total heap usage: 11 allocs, 11 frees, 74,860 bytes allocated
==74483== 
==74483== All heap blocks were freed -- no leaks are possible
==74483== 
==74483== For lists of detected and suppressed errors, rerun with: -s
==74483== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/

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