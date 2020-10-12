using namespace std;

class Car
{
public:
  string getMake();
  string getModel();
  int getYear();
  void setMake(string xmake);
  void setModel(string xmodel);
  void setYear(int xyear);

private:
  string make;
  string model;
  int year;
};