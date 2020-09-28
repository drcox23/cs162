// Douglas Cox
// Week 1, Exercise 2

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int choice;
  bool orderComplete = false;

  cout << "*** Doug's Diner  - Side Menu *** \n"
       << "1 - fries \n"
       << "2 - salad \n"
       << "3 - baked beans \n"
       << "4 - rice \n"
       << "5 - baked potato \n"
       << "6 - finalize order and exit \n"
       << "Enter a choice" << endl;

  // do-while statement to allow user to input until order is finalized
  do
  {
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "You chose fries!" << endl;
      break;
    case 2:
      cout << "You chose salad!" << endl;
      break;
    case 3:
      cout << "You chose baked beans!" << endl;
      break;
    case 4:
      cout << "You chose rice!" << endl;
      break;
    case 5:
      cout << "You chose baked potato!" << endl;
      break;
    case 6:
      orderComplete = true; //exit do-while statement.
      cout << "Thank you! Your order will be ready soon!" << endl;
      break;
    default:
      cout << "Choice not available! Please re-enter a valid side option" << endl;
      break;
    }
  } while (!orderComplete);

  return 0;
}