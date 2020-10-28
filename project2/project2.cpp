// Douglas Cox
// CS162 - Project 2
// This is the main file of the program that allows the user to add, delete, print, or export their stock watchlist.

#include <iostream>
#include <string>
#include "stocks.h"

using namespace std;

int main()
{
  int input;
  int count = 0;
  Stocks watchlist[MAX_SIZE];

  do
  {
    showOptions(input);
    if (input == 1)
    {
      importFromFile(watchlist, count);
    }
    else if (input == 2)
    {
      addStock(watchlist, count);
    }
    else if (input == 3)
    {
      showWatchlist(watchlist, count);
    }
    else if (input == 4)
    {
      if (count > 0)
      {
        deleteStock(watchlist, count);
        cout << "\nOk. Here is the updated watchlist:" << endl;
        showWatchlist(watchlist, count);
      }
      else
      {
        cout << "Please add a stock to the watchlist in order to be able to delete a stock from the watchlist." << endl;
      }
    }
    else if (input == 5)
    {
      exportToFile(watchlist, count);
    }

  } while (input != 6);

  cout << "Thank you for using our program!! The program shall now quit" << endl;

  return (0);
}
