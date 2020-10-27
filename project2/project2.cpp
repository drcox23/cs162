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

void showOptions(int &);
void addStock(Stocks[], int &);
void showWatchlist(Stocks[], int);
void deleteStock(Stocks[], int &);

int main()
{
  const int MAX_SIZE = 50;
  int input;
  int count = 0;
  Stocks watchlist[MAX_SIZE];

  do
  {
    showOptions(input);

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

  } while (input != 4);

  cout << "Thank you for using our program!! The program shall now quit" << endl;

  return (0);
}

// show menu options for creating a watchlist for stocks
void showOptions(int &selection)
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

  selection = choice;
}

// add a stock to the watchlist
void addStock(Stocks collection[], int &watchlistSize)
{

  cout << "enter company name" << endl;
  cin >> collection[watchlistSize].company;

  while (cin.fail())
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid company name" << endl;
    cin >> collection[watchlistSize].stockPrice;
  }

  cout << "enter stock symbol" << endl;
  cin >> collection[watchlistSize].symbol;

  while (cin.fail())
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid stock symbol" << endl;
    cin >> collection[watchlistSize].stockPrice;
  }

  cout << "enter today's stock price" << endl;
  cin >> collection[watchlistSize].stockPrice;

  while (cin.fail() || collection[watchlistSize].stockPrice < 0)
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Please enter a valid price (number greater than 0)" << endl;
    cin >> collection[watchlistSize].stockPrice;
  }

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
      cout << "company name: " << collection[i].company << endl
           << "stock symbol: " << collection[i].symbol << endl
           << "stock price: " << collection[i].stockPrice << endl;
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

  for (int i = (stockSelect - 1); i < size; i++)
  {
    collection[i].company = collection[i + 1].company;
    collection[i].symbol = collection[i + 1].symbol;
    collection[i].stockPrice = collection[i + 1].stockPrice;
  }

  size--;
}