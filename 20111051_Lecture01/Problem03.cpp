#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main()
{
	int result1;
	int result2;
	int result3;
	double average;
	srand(time(0));
	result1 = rand() % 12 + 1;
	cout << "Run #1: " << result1 << endl;
	result2 = rand() % 12 + 1;
	cout << "Run #2: " << result2 << endl;
	result3 = rand() % 12 + 1;
	cout << "Run #3: " << result3 << endl;
	average = double (result1+result2+result3) / 3;
	cout << "Average: " << average;
	return 0;
}