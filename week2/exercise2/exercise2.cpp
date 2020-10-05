// Douglas Cox
// Week 2, Exercise 2 - Daily Temperatures

#include <iostream>
#include <string>

using namespace std;

// functional prototypes
double calcHigh(double[], int);
double calcLow(double[], int);

int main()
{
  const int MAX_TEMP_INPUTS = 100;
  double temps[MAX_TEMP_INPUTS];
  int arraySize;
  double tempSum;

  // create array of temps
  for (int i = 0; i < MAX_TEMP_INPUTS; i++)
  {
    arraySize++;

    cout << "Enter temperature (enter -1 to quit)" << endl;
    cin >> temps[i];

    if (temps[i] == -1)
    {
      break;
    }
  }

  cout << "The temperatures are: " << endl;
  for (int j = 0; j < (arraySize - 1); j++)
  {
    cout << temps[j] << endl;

    // calculate sum of all temps
    tempSum = tempSum + temps[j];
  }

  cout << "The average temperature is: " << (tempSum / (arraySize - 1)) << endl; //calculate average temp
  cout << "The maximum temperature is: " << calcHigh(temps, arraySize) << endl;
  cout << "The minimum temperature is: " << calcLow(temps, arraySize) << endl;

  return (0);
}

//find highest temp
double calcHigh(double temperatures[], int size)
{
  double highTemp = temperatures[0];

  for (int i = 0; i < (size - 1); i++)
  {
    if (temperatures[i] > highTemp)
    {
      highTemp = temperatures[i];
    }
  }
  return highTemp;
}

// find lowest temp
double calcLow(double temperatures[], int size)
{
  double lowTemp = temperatures[0];

  for (int i = 0; i < (size - 1); i++)
  {
    if (temperatures[i] < lowTemp)
    {
      lowTemp = temperatures[i];
    }
  }
  return lowTemp;
}