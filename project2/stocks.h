// Douglas Cox
// This program is designed to help you build a watchlist of Stocks based on the inputs the user enters.cin.ignore(100, '\n'); This is the header file with the class defined and the functio prototypes used in the program.

#include <string>

using namespace std;

const int MAX_SIZE = 50;

class Stocks
{
public:
  string getCompany();
  string getSymbol();
  float getStockPrice();
  void setCompany(string);
  void setSymbol(string);
  void setStockPrice(float);
  Stocks(); //default constructor

private:
  string company;
  string symbol;
  float stockPrice;
};

// function prototypes

void showOptions(int &);
void addStock(Stocks[], int &);
void showWatchlist(Stocks[], int);
void deleteStock(Stocks[], int &);
void exportToFile(Stocks[], int);
void importFromFile(Stocks[], int &);