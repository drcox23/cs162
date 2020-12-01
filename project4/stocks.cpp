// Douglas Cox
// This is the implementation file building out the various functions and methods of the program.

#include <cstring>
#include "stocks.h"
#include <iostream>

using namespace std;

const char *Stocks::getCompany()
{
  return company;
}

const char *Stocks::getSymbol()
{
  return symbol;
}

float Stocks::getStockPrice()
{
  return stockPrice;
}

void Stocks::print()
{
  cout << "\n=== Stock ===" << endl;
  cout << "Company: " << company << endl
       << "Symbol: " << symbol << endl
       << "Stock Price: " << stockPrice << endl;
}

void Stocks::setCompany(const char *xcompany)
{
  if (company != NULL)
  {
    delete[] company;
  }
  company = new char[strlen(xcompany) + 1];
  strcpy(company, xcompany);
}

void Stocks::setSymbol(const char *xsymbol)
{
  if (symbol != NULL)
  {
    delete[] symbol;
  }
  symbol = new char[strlen(xsymbol) + 1];
  strcpy(symbol, xsymbol);
}

void Stocks::setStockPrice(float xstockPrice)
{
  stockPrice = xstockPrice;
}

Stocks::Stocks()
{
  company = new char[MAX_SIZE + 1];
  strcpy(company, "<no value>");

  symbol = new char[MAX_SIZE + 1];
  strcpy(symbol, "<no value>");

  stockPrice = 0.0;
}

Stocks::Stocks(const char *xcompany, const char *xsymbol, float xprice)
{
  company = NULL;
  setCompany(xcompany);

  symbol = NULL;
  setSymbol(xsymbol);

  stockPrice = xprice;
}

Stocks::~Stocks()
{
  delete[] company;
  delete[] symbol;
}

Stocks::Stocks(const Stocks &cpy)
{
  company = new char[strlen(cpy.company) + 1];
  strcpy(company, cpy.company);

  symbol = new char[strlen(cpy.symbol) + 1];
  strcpy(symbol, cpy.symbol);

  stockPrice = cpy.stockPrice;
}

const Stocks Stocks::operator=(const Stocks &cpy)
{
  if (this != &cpy)
  {
    if (company != NULL)
      delete[] company;
    company = new char[strlen(cpy.company) + 1];
    strcpy(company, cpy.company);

    if (symbol != NULL)
      delete[] symbol;
    symbol = new char[strlen(cpy.symbol) + 1];
    strcpy(symbol, cpy.symbol);

    stockPrice = cpy.stockPrice;
  }
  return *this; //return this object
}