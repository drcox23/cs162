//Douglas Cox
// CS 162
// Implementation file for List Class

#include <iostream>
#include <cstring>
#include "list.h"

using namespace std;

void List::addCar(const char *lmake, const char *lmodel, int lyear)
{
  carList[count].setMake(lmake);
  carList[count].setModel(lmodel);
  carList[count].setYear(lyear);

  count++;
}

void List::printList()
{
  for (int i = 0; i < count; i++)
  {
    cout << "\n== Car " << i + 1 << " ==" << endl;
    carList[i].print();
    cout << endl;
  }
}

List::List()
{
  count = 0;
}

int List::getCount()
{
  return count;
}