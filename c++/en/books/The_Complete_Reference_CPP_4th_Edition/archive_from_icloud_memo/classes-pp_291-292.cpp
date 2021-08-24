// Classes, pp.291-292

#include <iostream>
#include <cstring>

using namespace std;

class employee
{
  char name[90];
  double wage;
public:
  void put_name(char *n);
  void get_name(char *n);
private:
  void put_wage(double w);
  double get_wage();
};

void employee::put_name(char *n)
{
  strcpy(name,n);
}

void employee::get_name(char *n)
{
  strcpy(n, name)
}

void employee::put_wage(double w)
{
  wage = w;
}

double employee::get_wage()
{
  return wage;
}

int main()
{
  employee ted;
  char his_name[80];

  ted.put_name(“Ted Jones”);
  ted.put_wage(75000);
  ted.get_name( his_name );

  cout << his_name << “ makes $”;
  cout << ted.get_wage() << “ per year.” << endl;

  return 0;
}
