//Douglas Cox
// CS 162
// implementation file of general functions used in this program.

#include "functions.h"
//#include "collections.h"
#include <iostream>
#include <fstream>

using namespace std;

// show menu options for creating a watchlist for stocks
void showOptions(int &selection)
{
  int choice;

  // show menu options
  cout << "\n=== Main Menu ===" << endl;
  cout << "1 - bring in existing watchlist from a file" << endl
       << "2 - add a stock to the watchlist" << endl
       << "3 - print stock watchlist" << endl
       << "4 - delete stock from watchlist" << endl
       << "5 - export collection to a file" << endl
       << "6 - quit the program" << endl;
  cout << "Please enter a choice (1 to 6)" << endl;
  cin >> choice;

  // input validation
  while (cin.fail() || choice > 6 || choice < 1)
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid number between 1 and 6" << endl;
    cin >> choice;
  }
  cin.ignore(100, '\n');

  selection = choice;
}

