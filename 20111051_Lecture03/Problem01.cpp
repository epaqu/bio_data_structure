#include <iostream>
#include <string>
using namespace std;

int main()
{
	int data[2][8];
	data[0][0] = 20130113;
	data[0][1] = 20130502;
	data[0][2] = 20131124;
	data[0][3] = 20130370;
	data[0][4] = 20130238;
	data[0][5] = 20130076;
	data[0][6] = 20131043;
	data[0][7] = 20130759;
	data[1][0] = 10;
	data[1][1] = 4;
	data[1][2] = 32;
	data[1][3] = 12;
	data[1][4] = 1;
	data[1][5] = 20;
	data[1][6] = 7;
	data[1][7] = 13;
	int largest, id;
	for (int i = 0; i<8; i++)
	{
		largest = data[1][i];
		id = data[0][i];
		for (int j = i; j<8; j++)
		{
			if (largest < data[1][j])
			{
				largest = data[1][j];
				data[1][j] = data[1][i];
				data[1][i] = largest;
				id = data[0][j];
				data[0][j] = data[0][i];
				data[0][i] = id;
			}
		}
	}
	cout << "ID \t\tMidTerm Rank" << endl;
	for (int j = 0; j<8; j++)
	{
		cout << data[0][j] << "\t" << data[1][j] << endl;
	}
}