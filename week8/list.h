// Douglas Cox
// CS162
// Header file to define List Class used in this program

#include <cstring>
#include <iostream>
#include "car.h"

using namespace std;

struct Node
{
  Car *data;
  Node *next;
};

class List
{
public:
  void addCar(const char *, const char *, int);
  void addToList(Car *);
  void printList();
  void deleteCar();
  List();  //default constructor
  ~List(); // default destructor

private:
  Node *head;
  Node *tail;
};
