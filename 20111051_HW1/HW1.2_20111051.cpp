#include <iostream>
using namespace std;

int doubleFactorial(int n)
{
	int result = 1;
	for (int i = n; i > 0; i -= 2)
	{
		result *= i;
	}
	return result;
}

int recursiveDoubleFactorial(int n)
{
	if (n <= 1)
		return 1;
	return (n * doubleFactorial(n-2));
}


int main()
{
	cout << doubleFactorial(8) << endl;
	cout << recursiveDoubleFactorial(8) << endl;
}