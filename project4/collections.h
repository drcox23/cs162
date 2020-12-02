// Douglas Cox
// CS162 - Project 4
// This is the header file for the collection class used for this program

#include <cstring>
#include "stocks.h"

struct Node
{
  Stocks *data;
  Node *next;
};

class Collections
{
public:
  void addStockToList(Stocks *);
  void newStock();
  void showWatchlist(); //print list
  void deleteStock();
  void exportToFile();
  void importFromFile();

  Collections();  // default constructor
  ~Collections(); // default deconstructor

private:
  Node *head;
  Node *tail;
};