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

  recPrint(current);
}

void List::recPrint(Node *currNode)
{
  if (!currNode)
  {
    return;
  }
  else
  {
    currNode->data->print();
    return recPrint(currNode->next);
  }
}

List::List()
{
  head = NULL;
  tail = NULL;
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
  Node *newNode = new Node;

  newNode->data = newCar;

  newNode->next = NULL;

  if (!head)
  {
    head = newNode;
    return;
  }

  Node *current = head;
  Node *previous = NULL;

  while (current)
  {
    if (strcmp(current->data->getMake(), newNode->data->getMake()) > 0)
    {
      newNode->next = current;
      if (!previous)
      {
        head = newNode;
      }
      else
      {
        previous->next = newNode;
      }
      return;
    }
    previous = current;
    current = current->next;
  }

  previous->next = newNode;
}

void List::deleteCar()
{
  if (!head)
  {
    cout << "\nThe list is empty, no cars to delete" << endl;
    return;
  }

  cout << "\nHere is the list of cars to delete:" << endl;
  printList();

  char name[20];

  cout << "\nPlease enter what make you'd like to delete" << endl;
  cin >> name;

  Node *current = head; // first node
  Node *previous = NULL;

  while (current)
  {
    const char *currName = current->data->getMake();
    if (strcmp(name, currName) == 0)
    {
      // do something
      if (!previous)
      {
        head = head->next;
      }
      else
      {
        previous->next = current->next;
      }
      delete current->data;
      delete current;

      cout << "\nUpdated list:" << endl;
      printList();

      return;
    }

    previous = current;
    current = current->next;
  }

  cout << "\nNo makes were found by that name, please try again" << endl;
}