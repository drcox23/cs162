// Douglas Cox
// Week 2, Exercise 1 - Simple Calculator

#include <iostream>
#include <string>

using namespace std;

// functional prototypes
double calc(int);
double divCheck(double, int);
void printMenu();

int main()
{
  int firstNum;

  cout << "***Calculator Program***" << endl;
  cout << "Enter first Number:" << endl;

  cin >> firstNum;

  // perform calculations
  calc(firstNum);

  cout << "Thank you for using our app!!!" << endl;

  return (0);
}

// operator choices
void printMenu()
{
  cout << "***enter operator choice***\n"
       << "a - add\n"
       << "s - subtract\n"
       << "m - multiply\n"
       << "d - divide\n"
       << "q - quit\n"
       << "choice: " << endl;
}

double calc(int first)
{
  bool calcOn = true;
  double subtotal = first;
  int secondNum;
  char mathOp;

  do
  {
    printMenu();

    cin >> mathOp;
    mathOp = tolower(mathOp);

    if (mathOp == 'q')
    {
      calcOn = false;
    }
    else
    {
      cout << "Enter second number:";

      cin >> secondNum;

      if (mathOp == 'a')
      {
        double add = subtotal + secondNum;
        subtotal = add;
      }
      else if (mathOp == 's')
      {
        double subtract = subtotal - secondNum;
        subtotal = subtract;
      }
      else if (mathOp == 'm')
      {
        double multiply = subtotal * secondNum;
        subtotal = multiply;
      }
      else if (mathOp == 'd')
      {
        subtotal = divCheck(subtotal, secondNum);
      }
      cout << "The subtotal is: " << subtotal << endl;
    }

  } while (calcOn == true);

  cout << "The final total is: " << subtotal << endl;

  return subtotal;
}

// check if trying to divide by zero.
double divCheck(double sub, int newNum)
{
  double newSub;
  if (newNum == 0)
  {
    newSub = sub;
    cout << "Can't divide by zero" << endl;
  }
  else
  {
    double divide = sub / newNum;
    newSub = divide;
  }
  return newSub;
}