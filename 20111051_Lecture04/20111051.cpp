// 조교님들 수고하십니당!ㅎㅎ//

#include <iostream>
using namespace std;

int main()
{
	int *dynamicArray;
	int size;
	double tot=0;
	cout << "Size of the array? ";
	cin >> size;
	dynamicArray = new int[size];
	for (int i=0; i < size; i++)
	{
		cout << "\nType an integer: ";
		cin >> dynamicArray[i];
	}
	cout << "\nValues in the array are: ";
	for (int i=0; i < size; i++)
	{
		cout << dynamicArray[i] << " ";
		tot += double(dynamicArray[i]);
	}
	cout << "\nThe average of all the values is " << tot/size << endl;
	delete[] dynamicArray;
	return 0;
}