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
  //int count = 0;
  Stocks watchlist[MAX_SIZE];

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
      addStock(list);
    }
    else if (input == 3)
    {
      list.showWatchlist();
    }
    else if (input == 4)
    {
      if (list.getCount() > 0)
      {
        list.deleteStock();
        cout << "\nOk. Here is the updated watchlist:" << endl;
        list.showWatchlist();
      }
      else
      {
        cout << "Please add a stock to the watchlist in order to be able to delete a stock from the watchlist." << endl;
      }
    }
    else if (input == 5)
    {
      list.exportToFile();
    }
  } while (input != 6);

  cout << "Thank you for using our program!! The program shall now quit" << endl;

  return (0);
}
