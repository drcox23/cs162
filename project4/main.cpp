// Douglas Cox
// CS162 - Project 4
// This is the main file of the program that allows the user to add, delete, print, or export their stock watchlist.

#include <iostream>
#include <cstring>
#include "functions.h"
//#include "collections.h"

using namespace std;

int main()
{
  int input;

  Collections list;

  do
  {
    showOptions(input);
    if (input == 1)
    {
      list.importFromFile();
    }
    else if (input == 2)
    {
      list.newStock();
    }
    else if (input == 3)
    {
      list.showWatchlist();
    }
    else if (input == 4)
    {
      list.deleteStock();
    }
    else if (input == 5)
    {
      list.exportToFile();
    }
  } while (input != 6);

  cout << "Thank you for using our program!! The program shall now quit" << endl;

  return (0);
}

/*
Valgrind Output:

==28362== 
==28362== HEAP SUMMARY:
==28362==     in use at exit: 0 bytes in 0 blocks
==28362==   total heap usage: 33 allocs, 33 frees, 93,122 bytes allocated
==28362== 
==28362== All heap blocks were freed -- no leaks are possible
==28362== 
==28362== For lists of detected and suppressed errors, rerun with: -s
==28362== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/