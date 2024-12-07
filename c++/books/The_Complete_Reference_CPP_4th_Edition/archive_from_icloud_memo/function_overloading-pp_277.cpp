// Function Overloading, p.277

#include <iostream>
#include <cstdio>
#include <cstring>

void stradd(char *s1, char *s2);
void stradd(char *s1, int i);

int main()
{
  char str[80];

  strcpy(str, “hello, “);
  cout << “str = “ << str << endl;
  stradd(str, “world!”);
  cout << “str = “ << str << endl;

  stradd( str, 100 );
  cout << “str = “ << str << endl;

  return 0;
}

// Concatenate two strings
void stradd(char *s1, char *s2)
{
  strcat( s1, s2);
}

// Concatenate a string with a “stringized” integer
void stradd(char *s1, int i)
{
  char temp[80];

  sprintf(temp, “%d”, i);
  strcat(s1, temp);
}
