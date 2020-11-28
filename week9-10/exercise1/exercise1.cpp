// Douglas Cox
// CS 162
// This program shall provide the sum of numbers between 1 and a given number using recursion.

#include <iostream>

using namespace std;

//function prototype
int sum(int, int);

int main()
{
  int numEntered;

  cout << "Please enter any whole integer greater than 3" << endl;

  cin >> numEntered;

  cout << "The sum of all numbers between 1 and " << numEntered << " is: " << sum(numEntered, 0) << endl;

  return (0);
}

int sum(int numEntered, int totalSum)
{

  if (numEntered > 1)
  {
    int add = numEntered + (numEntered - 1);
    totalSum = totalSum + add;

    numEntered = numEntered - 2;

    return sum(numEntered, totalSum);
  }

  return totalSum;
}
