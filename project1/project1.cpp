// Douglas Cox
// CS162 - Project 1

#include <iostream>
#include <string>

using namespace std;

// determine struct for Stocks
struct Stocks
{
  string company;
  string symbol;
  float stockPrice;
};

int showOptions();
void addStock(Stocks[], int &);
void showWatchlist(Stocks[], int);
void deleteStock(int);

int main()
{
  const int MAX_SIZE = 50;

  int count = 0;
  int input;
  Stocks watchlist[MAX_SIZE];

  do
  {
    input = showOptions();
    if (input == 1)
    {
      addStock(watchlist, count);
    }
    else if (input == 2)
    {
      showWatchlist(watchlist, count);
    }
    else if (input == 3)
    {
      //code
    }

  } while (showOptions() != 4);

  cout << "Thank you for using our program!! The program shall now quit" << endl;

  return (0);
}

int showOptions()
{
  int choice;

  // show menu options
  cout << "\n=== Main Menu ===" << endl;
  cout << "1 - add a stock to the watchlist" << endl
       << "2 - print stock watchlist" << endl
       << "3 - delete stock from watchlist" << endl
       << "4 - quit the program" << endl;
  cout << "Please enter a choice (1 to 4)" << endl;
  cin >> choice;

  // input validation
  while (cin.fail() || choice > 4 || choice < 1)
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid number between 1 and 4" << endl;
    cin >> choice;
  }

  return choice;
}

void addStock(Stocks collection[], int &watchlistSize)
{
  //int size = watchlistSize;
  cout << "enter company name" << endl;
  cin >> collection[watchlistSize].company;

  cout << "enter stock symbol" << endl;
  cin >> collection[watchlistSize].symbol;

  cout << "enter today's stock price" << endl;
  cin >> collection[watchlistSize].stockPrice;

  while (cin.fail())
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid price" << endl;
    cin >> collection[watchlistSize].stockPrice;
  }

  watchlistSize++;
}

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
      cout << "company name: " << collection[i].company << endl
           << "stock symbol: " << collection[i].symbol << endl
           << "stock price: " << collection[i].stockPrice << endl;
    }
  }
}
