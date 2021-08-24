// Constructors and Descructors, pp.285~287
#include <iostream>
using namespace std;

#define SIZE 100

class stack
{
  int stck[SIZE];
  int tos;
public:
  stack();    // constructor
  ~stack(); // destructor
  void push(int i);
  int    pop();
};

// stack’s constructor
stack::stack()
{
  tos = 0;
  cout << “Stack initialized” << endl;
}

// stack’s destructor
stack::~stack()
{
  cout << “Stack destroyed” << endl;
}

void stack::push(int i)
{
  if ( SIZE <= tos)
  {
    cout << “Stack overflow” << endl;
  }
  stck[tos] = i;
  tos++;
}

int stack::pop()
{
  if (tos <= 0)
  {
    cout << “stack underflow” << endl;
    return 0;
  }
  tos—;
  return stck[tos]
}

int main()
{
  stack a, b;
  a.push(1);
  a.push(2);

  b.push(3);
  b.push(4);

  cout << a.pop() << “ “;
  cout << a.pop() << “ “;
  cout << b.pop() << “ “;
  cout << b.pop() << endl;

  return 0;
}
