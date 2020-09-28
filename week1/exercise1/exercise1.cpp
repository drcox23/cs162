// Douglas Cox
// Week 1, Exercise 1

#include <iostream>
#include <string>

using namespace std;

float animalYears(int); //functional prototype

int main()
{
  string name;
  int age;
  bool validAge;

  cout << "Please enter your name"
       << endl;
  cin >> name;
  cout << "Please enter your age"
       << endl;
  cin >> age;

  // input validation for age
  do
  {
    if (age > 0)
    {
      validAge = true;
    }
    else
    {
      cin.clear();
      cin.ignore(200, '\n');
      cout << "Please enter an age greater than 0 and in years." << endl;
      cin >> age;
      validAge = false;
    }
  } while (!validAge);

  cout << "Your Name: " << name << "\n"
       << "Your Age: " << age << "\n"
       << "Well... " << name << ", you may be " << age << " years old. \n"
       << "but if you were a wolf, you would be " << animalYears(age) << " years old!" << endl;

  return 0;
}

// function to calculate age in wolf years
float animalYears(int personAge)
{
  const int avgHumanAge = 75;
  const int avgWolfAge = 18;

  float animalAge = personAge * (avgHumanAge / avgWolfAge);
  return animalAge;
}