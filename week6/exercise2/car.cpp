// Douglas Cox
// Week 6, Exercise 2
// implementation file for Car class

#include <iostream>
#include <cstring>
#include "car.h"

using namespace std;

const char *Car::getMake()
{
  return make;
}

const char *Car::getModel()
{
  return model;
}

int Car::getYear()
{
  return year;
}

void Car::setMake(const char *xmake)
{
  if (make != NULL)
  {
    delete[] make;
  }

  make = new char[strlen(xmake) + 1];
  strcpy(make, xmake);
}

void Car::setModel(const char *xmodel)
{
  if (model != NULL)
  {
    delete[] model;
  }

  model = new char[strlen(xmodel) + 1];
  strcpy(model, xmodel);
}

void Car::setYear(int xyear)
{
  year = xyear;
}

void Car::print() const
{
  cout << "Make: " << make << endl
       << "Model: " << model << endl
       << "Year: " << year << endl;
}

Car::Car()
{
  make = new char[MAX_STR + 1];
  strcpy(make, "<no value>");

  model = new char[MAX_STR + 1];
  strcpy(model, "<no value>");

  year = 0;
}

Car::Car(const char *xmake, const char *xmodel, int xyear)
{
  make = NULL;
  setMake(xmake);
  model = NULL;
  setModel(xmodel);
  year = xyear;
}

Car::~Car()
{
  delete[] make;
  delete[] model;
}

Car::Car(const Car &cpy)
{
  make = new char[strlen(cpy.make) + 1];
  strcpy(make, cpy.make);

  model = new char[strlen(cpy.model) + 1];
  strcpy(model, cpy.model);

  year = cpy.year;
}

const Car Car::operator=(const Car &cpy)
{
  if (this != &cpy)
  {
    if (make != NULL)
      delete[] make;
    make = new char[strlen(cpy.make) + 1];
    strcpy(make, cpy.make);

    if (model != NULL)
      delete[] model;
    model = new char[strlen(cpy.model) + 1];
    strcpy(model, cpy.model);

    year = cpy.year;
  }
  return *this; //return this object
}
