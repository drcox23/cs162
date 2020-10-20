#include <cstring>

using namespace std;

const int MAX_STR = 100;

class Car
{
public:
  const char *getMake();
  const char *getModel();
  int getYear();
  void setMake(const char *);
  void setModel(const char *);
  void setYear(int);
  void print() const;
  Car();                                //default constructor
  Car(const char *, const char *, int); // constructor with member params
  ~Car();                               //destructor

private:
  char *make;
  char *model;
  int year;
};