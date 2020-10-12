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

private:
  string make;
  string model;
  int year;
};