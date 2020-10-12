// Douglas Cox
// Week 3, Exercise 1

#include <iostream>
#include <string>
#include "car.h"

using namespace std;

string Car::getMake()
{
  return make;
}

string Car::getModel()
{
  return model;
}

int Car::getYear()
{
  return year;
}

void Car::setMake(string xmake)
{
  make = xmake;
}

void Car::setModel(string xmodel)
{
  model = xmodel;
}

void Car::setYear(int xyear)
{
  year = xyear;
}