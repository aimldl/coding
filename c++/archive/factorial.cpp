#include <iostream>
using namespace std;

int
factorial(int num)
{
	if (num > 1)
	{
		return num * factorial(num - 1);
	}
	else if ( num>=0 )
	{
		return 1;
	}
}


int main()
{
  // Input
	int N;
	//cin >> N;
	N = 1;

	// Output
	cout << factorial(N) << endl;
	return 0;
}


