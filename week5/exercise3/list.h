// Douglas Cox
// CS162
// Header file to define List Class used in this program

#include <cstring>
#include "car.h"

//using namespace std;

class List
{
public:
  void addCar(const char *, const char *, int);
  void printList();
  List(); //default constructor
  int getCount();

private:
  Car carList[20];
  int count;
};
