// Douglas Cox
// This is the implementation file building out the various functions and methods of the program.

#include <iostream>
#include <fstream>
#include <string>
#include "stocks.h"

using namespace std;

string Stocks::getCompany()
{
  return company;
}

string Stocks::getSymbol()
{
  return symbol;
}

float Stocks::getStockPrice()
{
  return stockPrice;
}

void Stocks::setCompany(string xcompany)
{
  company = xcompany;
}

void Stocks::setSymbol(string xsymbol)
{
  symbol = xsymbol;
}

void Stocks::setStockPrice(float xstockPrice)
{
  stockPrice = xstockPrice;
}

Stocks::Stocks()
{
  company = "";
  symbol = "";
  stockPrice = 0;
}

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
void addStock(Stocks collection[], int &watchlistSize)
{
  string icompany;
  string isymbol;
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

  collection[watchlistSize].setCompany(icompany);

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

  collection[watchlistSize].setSymbol(isymbol);

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

  collection[watchlistSize].setStockPrice(istockPrice);

  watchlistSize++;
}

// show watchlist of stocks that the user has put together
void showWatchlist(Stocks collection[], int size)
{
  if (size < 1)
  {
    cout << "There are no stocks in your watchlist, please add a stock to your watchlist first" << endl;
  }
  else
  {
    for (int i = 0; i < size; i++)
    {
      cout << "\n--- " << (i + 1) << " ---" << endl;
      cout << "company name: " << collection[i].getCompany() << endl
           << "stock symbol: " << collection[i].getSymbol() << endl
           << "stock price: " << collection[i].getStockPrice() << endl;
    }
  }
}

// remove a stock from the watchlist
void deleteStock(Stocks collection[], int &size)
{
  int stockSelect;

  showWatchlist(collection, size);

  cout << "\nWhich stock would you like to remove from the watchlist? \n"
       << "Please enter the number associated with the stock" << endl;

  cin >> stockSelect;
  while (cin.fail() || (stockSelect > size) || stockSelect < 0)
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid stock number" << endl;
    cin >> stockSelect;
  }
  cin.ignore(100, '\n');

  for (int i = (stockSelect - 1); i < size; i++)
  {
    collection[i].setCompany(collection[i + 1].getCompany());
    collection[i].setSymbol(collection[i + 1].getSymbol());
    collection[i].setStockPrice(collection[i + 1].getStockPrice());
  }

  size--;
}

void exportToFile(Stocks collection[], int size)
{
  ofstream outfile;
  string fileName;

  cout << "What would you like to name the file (ex: watchlist.txt)" << endl;

  cin >> fileName;
  cin.ignore(100, '\n');

  outfile.open(fileName);

  for (int i = 0; i < size; i++)
  {
    outfile << collection[i].getCompany() << endl
            << collection[i].getSymbol() << endl
            << collection[i].getStockPrice() << endl;
  };

  cout << "Your file has been written to " << fileName;

  outfile.close();
}

void importFromFile(Stocks collection[], int &size)
{
  const int MAX_CHAR = 100;
  char filePath[MAX_CHAR];

  cout << "Please enter the name of your file" << endl;
  cin >> filePath;
  cin.ignore(100, '\n');
  //getline(cin, filePath[MAX_CHAR], '\n');
  //cin.getline(filePath, MAX_CHAR);

  char line[MAX_CHAR];
  double price;

  ifstream inFile;

  inFile.open(filePath);

  if (!inFile.is_open())
  {
    cout << "Sorry, but we can't open file " << filePath << ". Please try again." << endl;
    return;
  }

  while (inFile.getline(line, MAX_CHAR))
  {
    collection[size].setCompany(line);

    inFile.getline(line, MAX_CHAR);
    collection[size].setSymbol(line);

    inFile >> price;
    collection[size].setStockPrice(price);
    inFile.ignore(100, '\n');

    size++;
  }

  inFile.close();
}
