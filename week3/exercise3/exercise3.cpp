// Douglas Cox
// Week 3, Exercise 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// determine Employee struct
struct Employee
{
  int ID;
  float payRate;
  float hours;
  float grossPay;
};

// function prototype
void loadData();
void writeFile(Employee[], int);

int main()
{

  loadData();

  return (0);
}

void loadData()
{
  const string FILEPATH = "./payroll.txt";
  const int MAX_ROWS = 50;

  int employeeNum = 0;

  ifstream inFile;

  Employee employs[MAX_ROWS];

  inFile.open(FILEPATH);

  while (!inFile.eof())
  {
    inFile >> employs[employeeNum].ID >> employs[employeeNum].payRate >> employs[employeeNum].hours >> employs[employeeNum].grossPay;
    employeeNum++;
  }

  for (int i = 0; i < employeeNum; i++)
  {
    employs[i].grossPay = (employs[i].payRate * employs[i].hours);
  }

  writeFile(employs, employeeNum);

  inFile.close();
}

void writeFile(Employee empData[], int employeeNum)
{
  ofstream outfile;

  outfile.open("payrollupdate.txt");

  for (int i = 0; i < employeeNum - 1; i++)
  {
    outfile << empData[i].ID << endl
            << empData[i].payRate << endl
            << empData[i].hours << endl
            << empData[i].grossPay << endl;
  };

  cout << "Updated Payroll (written to file)" << endl;

  for (int i = 0; i < employeeNum - 1; i++)
  {
    cout << right << setw(10) << empData[i].ID << setw(10) << empData[i].payRate << setw(5) << empData[i].hours << setw(10) << empData[i].grossPay << endl;
  }
  outfile.close();
}