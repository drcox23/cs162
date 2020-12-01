// Douglas Cox
// CS162 - Project 3
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
