#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num, count, numSpace;
	cout << "Please type an odd number: " << endl;
	cin >> num;
	for (int i=1; i <= num; i+=2)
	{
		count = i;
		numSpace = (num - i)/2;
		while (numSpace > 0)
		{
			cout << " ";
			numSpace--;
		}
		numSpace = (num - i)/2;
		while (count > 0)
		{
			cout << "*";
			count= count - 1;
		}
		cout << endl;
	}
	for (int j=num-2; j > 0; j-=2)
	{
		count = j;
		numSpace = (num - j)/2;
		while (numSpace > 0)
		{
			cout << " ";
			numSpace--;
		}
		while (count > 0)
		{
			cout << "*";
			count = count - 1;
		}
		cout << endl;
	}
	return 0;
}