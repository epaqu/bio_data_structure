#include <iostream>
#include <string>
using namespace std;

int strCompare(char a[], char b[])
{
	int alength = strlen(a);
	int blength = strlen(b);
	if (int(a[0]) > int(b[0]))
		return 1;
	else if (int(a[0]) < int(b[0]))
		return -1;
	else
	{
		if (alength == 1 && blength == 1)
			return 0;
		else if (alength == 1)
			return 1;
		else if (blength == 1)
			return -1;
		char* new_a = a+1;
		char* new_b = b+1;
		strCompare(new_a, new_b);
	}
}

int main()
{
	char* city[6] = {"Seoul", "Daejeon", "Incheon", "Jeju", "Dokdo", "Daegu"};
	char* first;
	for (int i = 0; i<6; i++)
	{
		first = city[i];
		for (int j = i; j<6; j++)
		{
			if (strCompare(first, city[j]) == 1)
			{
				first = city[j];
				city[j] = city[i];
				city[i] = first;
			}
		}
	}
	for (int i = 0; i<6; i++)
	{
		cout << city[i] << endl;
	}
}