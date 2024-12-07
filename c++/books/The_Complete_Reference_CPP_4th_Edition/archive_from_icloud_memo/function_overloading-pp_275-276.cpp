// Function Overloading, pp.275~276

#include <iostream>
using namespace std;

// abs is overloaded three ways
int abs(int i);
double abs(double d);
long abs(long l);

int main()
{
  cout << “abs(-10) = “ << abs(-10) << endl;
  cout << “abs(-11.0) = “ << abs(-11.0) << endl;
  cout << “abs(-9L) = “ << abs(-9L) << endl;

  return 0;
}

int abs(int i)
{
  cout << “Using int abs()” << endl;
  return i<0 ? -i : i;
}

double abs(double d)
{
  cout << “Using double abs()” << endl;
  return d <0.0 ? -d : d;
}

long abs(long l)
{
  cout << “Using long abs()” << endl;
  return l <0 ? -l : l;
}
