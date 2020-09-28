// Douglas Cox
// Week 1, Exercise 3

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool playTime(char &, int &);

int main()
{
  srand((unsigned)time(NULL));

  int pot = 100;
  int bet;
  bool inPlay;
  char start;
  int dice1, dice2, sum;

  cout << "Would you like to play dice game? Please enter y/n" << endl;
  cin >> start;
  start = tolower(start);

  //start dice game if y is selected
  while (start != 'n')
  {
    // check if there are coins available in the pot
    if (pot > 0)
    {
      cout << "You have " << pot << " coins in your pot" << endl;
      cout << "How much do you want to bet?" << endl;
      cin >> bet;
      // validate bet
      if ((bet < 0) || (bet > pot))
      {
        do
        {
          cin.clear();
          cin.ignore(200, '\n');
          cout << "Sorry, that is an invalid bet. You can't bet more than your pot or a negative, please select a different amount" << endl;
          cin >> bet;
        } while ((bet > pot) || (bet < 0));
      }

      dice1 = (rand() % 6) + 1;
      dice2 = (rand() % 6) + 1;
      sum = dice1 + dice2;

      cout << "You rolled a " << dice1 << " and a " << dice2 << endl;
      cout << "For a sum of " << sum << endl;

      // rolled a loss
      if (sum == 2 || sum == 3 || sum == 12)
      {
        cout << "You lost!!!" << endl;

        // removed bet from pot
        pot = pot - bet;

        cout << "Would you like to continue? (y/n)" << endl;
        cin >> start;
        start = tolower(start);
        //playTime(start, pot);
      }

      // winning roll
      else if (sum == 7 || sum == 11)
      {
        cout << "You won!!!" << endl;

        // increase pot by bet size
        pot = pot + bet;

        cout << "Would you like to continue? (y/n)" << endl;
        cin >> start;
        start = tolower(start);
        //playTime(start, pot);
      }
      // rolled a draw.
      else
      {
        cout << "It's a draw. No change to pot" << endl;

        cout << "Would you like to continue? (y/n)" << endl;
        cin >> start;
        start = tolower(start);
        //playTime(start, pot);
      }
    }

    // all out of coins, exit game
    else
    {
      cout << "Sorry, you are all out of coins, the game shall now close" << endl;
      start = 'n';
    }
  }

  cout << "You have " << pot << " coins in your pot,\n"
       << "The game shall exit now. Thanks!" << endl;

  return (0);
}

// function for validation of y/n input. Still needs work
/*bool playTime(char &start, int &pot)
{
  bool playCheck = false;
  do
  {
    if (start == 'y')
    {
      playCheck = true;
      return true;
    }
    else if (start == 'n')
    {
      cout << "You have " << pot << " coins in your pot,\n"
           << "The game shall exit now. Thanks!" << endl;
      playCheck = true;
      return false;
    }
    else
    {
      cout << "Please enter y/n" << endl;
      cin >> start;
      start = tolower(start);
    }
  } while (!playCheck);
}
*/