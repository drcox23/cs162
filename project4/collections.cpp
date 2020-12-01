// Douglas Cox
// This is the implementation file to create the collection class for the stock list.

#include <iostream>
#include <fstream>
#include <cstring>
#include "collections.h"

using namespace std;

// add stock to the collection
void Collections::addStockToList(Stocks *addStock)
{

  Node *newNode = new Node;
  newNode->data = addStock;
  newNode->next = NULL;

  if (!head)
  {
    head = newNode;
    return;
  }

  Node *current = head;
  Node *previous = NULL;

  while (current)
  {
    if (strcmp(current->data->getCompany(), newNode->data->getCompany()) > 0)
    {
      newNode->next = current;
      if (!previous)
      {
        head = newNode;
      }
      else
      {
        previous->next = newNode;
      }
      return;
    }
    previous = current;
    current = current->next;
  }
  previous->next = newNode;
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

  Stocks *newStock;
  newStock = new Stocks(icompany, isymbol, istockPrice);

  addStockToList(newStock);
}

// show watchlist of stocks that the user has put together
void Collections::showWatchlist()
{
  if (!head)
  {
    cout << "There are no stocks in your watchlist, please add a stock to your watchlist first" << endl;
    return;
  }

  Node *current = head;
  while (current != NULL)
  {
    current->data->print();
    current = current->next;
  }
}

// remove stock from watchlist
void Collections::deleteStock()
{
  if (!head)
  {
    cout << "Please add a stock to the watchlist in order to be able to delete a stock from the watchlist." << endl;
    return;
  }

  char stockSelect[30];

  cout << "Here is a list of stocks to choose which to delete" << endl;
  showWatchlist();

  cout << "\nWhich stock would you like to remove from the watchlist? \n"
       << "Please enter the company in which you would like to remove from the stocklist" << endl;

  cin >> stockSelect;

  Node *current = head; //first node
  Node *previous = NULL;

  while (current)
  {
    const char *currStock = current->data->getCompany();
    if (strcmp(stockSelect, currStock) == 0)
    {
      if (!previous)
      {
        head = head->next;
      }
      else
      {
        previous->next = current->next;
      }
      delete current->data;
      delete current;

      cout << "\nOK. Here's the updated watchlist: " << endl;
      showWatchlist();

      return;
    }
    previous = current;
    current = current->next;
  }
}

void Collections::exportToFile()
{

  if (!head)
  {
    cout << "There are no stocks in your watchlist to export. Please add a stock to your watchlist first" << endl;
    return;
  }

  ofstream outfile;
  string fileName;

  cout << "What would you like to name the file (ex: watchlist.txt)" << endl;

  cin >> fileName;
  cin.ignore(100, '\n');

  outfile.open(fileName);

  Node *current = head;
  while (current != NULL)
  {
    outfile << current->data->getCompany() << endl
            << current->data->getSymbol() << endl
            << current->data->getStockPrice() << endl;
    current = current->next;
  }

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
    Stocks *newStock;
    newStock->setCompany(line);
    //watchlist[count].setCompany(line);

    inFile.getline(line, MAX_CHAR);
    newStock->setSymbol(line);

    inFile >> price;
    newStock->setStockPrice(price);
    inFile.ignore(100, '\n');

    addStockToList(newStock);
  }
  inFile.close();
}

Collections::Collections()
{
  head = NULL;
  tail = NULL;
}

Collections::~Collections()
{
  Node *curr = NULL;
  while (head != NULL)
  {
    curr = head;
    head = curr->next;
    delete curr->data;
    delete curr;
  }
}