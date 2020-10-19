#include <string>

using namespace std;

class Jewelry
{
public:
  string getMetal();
  int getLength();
  double getPrice();
  void setMetal(string);
  void setLength(int);
  void setPrice(double);
  Jewelry();                    // default constructor
  Jewelry(string, int, double); //constructor that takes in the attributes

private:
  string metal;
  int length;
  double price;
};