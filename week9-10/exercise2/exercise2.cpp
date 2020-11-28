// Douglas Cox
// CS 162
// This program shall provide the greatest common denominator between 2 integers using recursion.
// source of euclid algorithm = https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm

#include <iostream>

using namespace std;

//function prototype
int gcd(int, int);

int main()
{
  int xVar, yVar;

  cout << "Please enter two whole integer greater than 0" << endl;

  cin >> xVar >> yVar;
  while (cin.fail() || xVar < 0 || yVar < 0)
  {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Please enter whole integers numbers greater than 0" << endl;
    cin >> xVar >> yVar;
  }
  cin.ignore(100, '\n');

  if (xVar > yVar)
  {
    cout << "The greatest common denominator between " << xVar << " and " << yVar << " is: " << gcd(xVar, yVar) << endl;
  }
  else
  {
    cout << "The greatest common denominator between " << xVar << " and " << yVar << " is: " << gcd(yVar, xVar) << endl;
  }

  return (0);
}

int gcd(int x, int y)
{

  if (y > 0)
  {
    if (x % y == 0)
    {
      return y;
    }

    return gcd(y, (x % y));
  }

  return y;
}
