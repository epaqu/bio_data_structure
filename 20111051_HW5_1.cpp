#include <iostream>
#include <string>
using namespace std;

int checkdone(int size, char *arrays[])
{
	int winner = 1;
	int index = 0;
	int pos = 0;
	char ForS = 0;
	while (index < size)
	{
		winner = 1;
		for (int i = 0; i < size-1; i++)
		{
			if (arrays[index][i] != arrays[index][i+1] || arrays[index][i] == '*')
			{
				winner = 0;
			}
		}
		if (winner == 1)
		{
			ForS = 'f';
			pos = index;
			break;
		}
		winner = 1;
		for (int i = 0; i < size-1; i++)
		{
			if (arrays[i][index] != arrays[i+1][index] || arrays[i][index] == '*')
			{
				winner = 0;
			}
		}
		if (winner == 1)
		{
			ForS = 's';
			pos = index;
			break;
		}
		winner = 1;
		for (int i = 0; i < size-1; i++)
		{
			if (arrays[i][i] != arrays[i+1][i+1] || arrays[i][i] == '*')
			{
				winner = 0;
			}
		}
		if (winner == 1)
		{
			ForS = 'n';
			pos = 0;
			break;
		}
		winner = 1;
		for (int i = 0; i < size-1; i++)
		{
			if (arrays[i][size-1-i] != arrays[i+1][size-2-i] || arrays[i][size-1-i] == '*')
			{
				winner = 0;
			}
		}
		if (winner == 1)
		{
			ForS = 'm';
			pos = 0;
			break;
		}
		index++;
	}
	if (winner == 1 && ForS == 'f')
	{
		if (arrays[pos][0] == 'O')
		{	return 1;
		}
		else if (arrays[pos][0] == 'X')
		{	return 2;
		}
	}
	else if (winner == 1 && ForS == 's')
	{	if (arrays[0][pos] == 'O')
		{	return 1;}
		else if (arrays[0][pos] == 'X')
		{	return 2;}
	}
	else if (winner == 1 && ForS == 'n')
	{	if (arrays[pos][pos] == 'X')
		{	return 2;}
		else if (arrays[pos][pos] == 'O')
		{	return 1;}
	}
	else if (winner == 1 && ForS == 'm')
	{	if (arrays[pos][size-1] == 'X')
		{	return 2;}
		else if (arrays[pos][size-1] == 'O')
		{	return 1;}
	}
	return 0;
}
int main()
{
	int size=1, Oxcord, Oycord, Xxcord, Xycord, turn=0;
	while (size < 2)
	{
		cout << "Enter the size of the world (larger than 1): ";
		cin >> size;
	}
	char **array_ptr;
	array_ptr = new char* [size];
	for(int i=0; i<size;i++)
	{
		array_ptr[i] = new char[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array_ptr[i][j] = '*';
			cout << array_ptr[i][j] << " ";
		}
		cout << endl;
	}
	int numSpot = size * size;
	while (checkdone(size, array_ptr) == 0 && numSpot != 0)
	{
		if (turn == 0)
		{
			cout << "\nEnter the move of player 0.\nplayer 0's x-coordinate: ";
			cin >> Oxcord;
			cout << "\nplayer 0's y-coordinate: ";
			cin >> Oycord;
			if (Oxcord > size || Oycord > size)
			{
				cout << "That is an invalid input!";
				break;
			}
			else if(array_ptr[Oxcord-1][Oycord-1] != '*')
			{
				cout << "That is an invalid input!";
				break;
			}
			array_ptr[Oxcord-1][Oycord-1] = 'O';
			numSpot --;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					cout << array_ptr[j][i] << " ";
				}
				cout << endl;
			}
			turn = 1;
		}
		else if (turn == 1)
		{
			cout << "\nEnter the move of player X.\nplayer X's x-coordinate: ";
			cin >> Xxcord;
			cout << "\nplayer X's y-coordinate: ";
			cin >> Xycord;
			if (Xxcord > size || Xycord > size)
			{
				cout << "That is an invalid input!";
				break;
			}
			else if(array_ptr[Xxcord-1][Xycord-1] != '*')
			{
				cout << "That is an invalid input!";
				break;
			}
			array_ptr[Xxcord-1][Xycord-1] = 'X';
			numSpot --;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					cout << array_ptr[j][i] << " ";
				}
				cout << endl;
			}
			turn = 0;
		}
	}
	if (checkdone(size, array_ptr) == 1)
		cout << "Player O has won the game!" << endl;
	else if (checkdone(size, array_ptr) == 2)
		cout << "Player X has won the game!" << endl;
	else if (numSpot == 0)
		cout << "Draw!" << endl;
}
