// Douglas Cox
// This program is designed to help you build a watchlist of Stocks based on the inputs the user enters.This is the header file with the class defined and the functio prototypes used in the program.

#include <cstring>

using namespace std;

const int MAX_SIZE = 100;

class Stocks
{
public:
  const char *getCompany();
  const char *getSymbol();
  float getStockPrice();
  void setCompany(const char *);
  void setSymbol(const char *);
  void setStockPrice(float);
  Stocks();                                  //default constructor
  Stocks(const char *, const char *, float); // constructor with member parameters
  ~Stocks();                                 // destructor
  Stocks(const Stocks &cpy);                 // copy constructor

  const Stocks operator=(const Stocks &cpy); //operator override

private:
  char *company;
  char *symbol;
  float stockPrice;
};
