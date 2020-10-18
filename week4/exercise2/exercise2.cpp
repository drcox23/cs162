// Douglas Cox
// CS 162
// Week 4, Exercise 2

#include <iostream>

using namespace std;

int main()
{
  int arr[6] = {100, 25, 0, 90, 19, 30};
  int *ptr;
  ptr = arr;

  int size = 6;

  for (int i = 0; i < size; i++)
  {
    cout << *ptr << endl;
    ptr++;
  }

  return (0);
}