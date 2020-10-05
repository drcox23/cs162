// Douglas Cox
// Week 2, Exercise 3

#include <iostream>
#include <string>

using namespace std;

// determine struct members
struct Contact
{
  string name;
  string areaCode;
  string prefix;
  string suffix;
  string email;
};

int main()
{
  const int ARRAY_SIZE = 100;
  bool stopInfo = false;
  int contactCount;
  char makeContact;

  cout << "Please enter contact details" << endl;

  Contact contactInfo[ARRAY_SIZE];

  // while loop to collect info
  while (!stopInfo)
  {
    cin.clear();
    cin.ignore(200, '\n');

    cout << "=== Contact " << (contactCount + 1) << " ===" << endl;
    cout << "Enter Name: ";
    getline(cin, contactInfo[contactCount].name);
    cout << "Enter Phone Number's Area Code: ";
    cin >> contactInfo[contactCount].areaCode;
    cout << "Enter Phone Number's Prefix: ";
    cin >> contactInfo[contactCount].prefix;
    cout << "Enter Phone Number's Suffix: ";
    cin >> contactInfo[contactCount].suffix;
    cout << "Enter email: ";
    cin >> contactInfo[contactCount].email;
    cout << "Do you want to add another? ('y' or 'n')";
    cin >> makeContact;
    makeContact = tolower(makeContact);
    if (makeContact == 'n')
    {
      stopInfo = true;
    }
    contactCount++;
  }

  // printing for loop
  cout << "Printing Contacts" << endl;
  for (int i = 0; i < contactCount; i++)
  {
    cout << "=== Contact #" << (i + 1) << " ===" << endl;
    cout << "Name: " << contactInfo[i].name << endl;
    cout << "Phone Number: (" << contactInfo[i].areaCode << ") " << contactInfo[i].prefix << " - " << contactInfo[i].suffix << endl;
    cout << "email: " << contactInfo[i].email << endl;
  }

  return (0);
}
