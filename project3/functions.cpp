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

// add a stock to the watchlist
void addStock(Collections watchlist)
{
  char icompany[MAX_SIZE];
  char isymbol[MAX_SIZE];
  float istockPrice;

  cout << "enter company name" << endl;
  cin >> icompany;

  while (cin.fail())
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid company name" << endl;
    cin >> icompany;
  }
  cin.ignore(100, '\n');

  cout << "enter stock symbol" << endl;
  cin >> isymbol;

  while (cin.fail())
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid stock symbol" << endl;
    cin >> isymbol;
  }
  cin.ignore(100, '\n');

  cout << "enter today's stock price" << endl;
  cin >> istockPrice;

  while (cin.fail() || istockPrice < 0)
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid price (number greater than 0)" << endl;
    cin >> istockPrice;
  }
  cin.ignore(100, '\n');

  watchlist.addStockToList(icompany, isymbol, istockPrice);
}
