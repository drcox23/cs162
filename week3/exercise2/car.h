using namespace std;

class Car
{
public:
  string getMake();
  string getModel();
  int getYear();
  void setMake(string);
  void setModel(string);
  void setYear(int);
  Car();                    //default constructor
  Car(string, string, int); // constructor with member params

private:
  string make;
  string model;
  int year;
};