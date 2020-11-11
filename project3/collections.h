// Douglas Cox
// CS162 - Project 3
// This is the header file for the collection class used for this program

#include <cstring>
#include "stocks.h"

class Collections
{
public:
  void addStockToList(const char *, const char *, float);
  void showWatchlist(); //print list
  void deleteStock();
  void exportToFile();
  void importFromFile();

  int getCount();

  Collections(); // default constructor

private:
  Stocks watchlist[20];
  int count;
};