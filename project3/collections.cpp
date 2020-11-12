// Douglas Cox
// This is the implementation file to create the collection class for the stock list.

#include <iostream>
#include <fstream>
#include <cstring>
#include "collections.h"

using namespace std;

// add stock to the collection
void Collections::addStockToList(const char *xcompany, const char *xsymbol, float xprice)
{

  watchlist[count].setCompany(xcompany);
  watchlist[count].setSymbol(xsymbol);
  watchlist[count].setStockPrice(xprice);

  count++;

  cout << getCount() << endl;
}

// get new stock to add from user
void Collections::newStock()
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

  addStockToList(icompany, isymbol, istockPrice);
}

// show watchlist of stocks that the user has put together
void Collections::showWatchlist()
{
  if (count < 1)
  {
    cout << "There are no stocks in your watchlist, please add a stock to your watchlist first" << endl;
  }
  else
  {
    for (int i = 0; i < count; i++)
    {
      cout << "\n--- " << (i + 1) << " ---" << endl;
      cout << "company name: " << watchlist[i].getCompany() << endl
           << "stock symbol: " << watchlist[i].getSymbol() << endl
           << "stock price: " << watchlist[i].getStockPrice() << endl;
    }
  }
}

// remove stock from watchlist
void Collections::deleteStock()
{
  int stockSelect;

  showWatchlist();

  cout << "\nWhich stock would you like to remove from the watchlist? \n"
       << "Please enter the number associated with the stock" << endl;

  cin >> stockSelect;
  while (cin.fail() || (stockSelect > count) || stockSelect < 0)
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid stock number" << endl;
    cin >> stockSelect;
  }
  cin.ignore(100, '\n');

  for (int i = (stockSelect - 1); i < count; i++)
  {

    watchlist[i].setCompany(watchlist[i + 1].getCompany());
    watchlist[i].setSymbol(watchlist[i + 1].getSymbol());
    watchlist[i].setStockPrice(watchlist[i + 1].getStockPrice());
  }

  count--;
}

void Collections::exportToFile()
{
  ofstream outfile;
  string fileName;

  cout << "What would you like to name the file (ex: watchlist.txt)" << endl;

  cin >> fileName;
  cin.ignore(100, '\n');

  outfile.open(fileName);

  for (int i = 0; i < count; i++)
  {
    outfile << watchlist[i].getCompany() << endl
            << watchlist[i].getSymbol() << endl
            << watchlist[i].getStockPrice() << endl;
  };

  cout << "Your file has been written to " << fileName;

  outfile.close();
}

void Collections::importFromFile()
{
  const int MAX_CHAR = 100;
  char filePath[MAX_CHAR];

  cout << "Please enter the name of your file" << endl;
  cin >> filePath;
  cin.ignore(100, '\n');

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
    watchlist[count].setCompany(line);

    inFile.getline(line, MAX_CHAR);
    watchlist[count].setSymbol(line);

    inFile >> price;
    watchlist[count].setStockPrice(price);
    inFile.ignore(100, '\n');

    count++;
  }
  inFile.close();
}

int Collections::getCount()
{
  return count;
}

Collections::Collections()
{
  count = 0;
}