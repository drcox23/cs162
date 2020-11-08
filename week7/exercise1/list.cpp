//Douglas Cox
// CS 162
// Implementation file for List Class

#include <iostream>
#include <cstring>
#include "list.h"

using namespace std;

void List::addCar(const char *lmake, const char *lmodel, int lyear)
{
  Car *newCar;
  newCar = new Car(lmake, lmodel, lyear);
  addToList(newCar);
}

void List::printList()
{
  if (!head)
  {
    cout << "There are no cars in the list." << endl;
    return;
  }

  Node *current = head;
  while (current != NULL)
  {
    current->data->print();
    current = current->next;
  }
}

List::List()
{
  head = NULL;
}

List::~List()
{
  Node *curr = NULL;
  while (head != NULL)
  {
    curr = head;
    head = curr->next;
    delete curr->data;
    delete curr;
  }
}

void List::addToList(Car *newCar)
{
  Node *new_ptr = new Node;

  new_ptr->data = newCar;

  new_ptr->next = head;
  head = new_ptr;
}