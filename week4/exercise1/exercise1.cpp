// Douglas Cox
// CS 162
// Week 4, Exercise 1

#include <iostream>

using namespace std;

int main()
{
  int num = 14;
  int *ptr;
  ptr = &num;

  cout << "This is the value of num: " << num << endl;
  cout << "This is the value of ptr: " << ptr << endl;
  cout << "This is the value of *ptr: " << *ptr << endl;

  num = 18;
  cout << "This is the new value of num: " << num << endl;
  cout << "This is the new value of *ptr: " << *ptr << endl;

  *ptr = 53;
  cout << "This is the newest value of num: " << num << endl;
  cout << "This is the newest value of *ptr: " << *ptr << endl;

  return (0);
}