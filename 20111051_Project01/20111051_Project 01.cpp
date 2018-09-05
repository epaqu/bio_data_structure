#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define gap -4

int score(int i, int j, char* Fseq, char* Sseq, int** subsMat)
{
	if (Fseq[i] == '-' || Sseq[i] == '-')
		return gap;
	if (Fseq[i] == Sseq[j])
		return subsMat[0][0];
	return subsMat[0][1];
}
int** scoreMat(int m, int n, char* Fseq, char* Sseq, int ** subsMat)
{
	int **result;
	result = new int* [m];
	for(int index=0; index < m;index++)
	{
		result[index] = new int[n];
	}
	result[0][0] = score(0, 0, Fseq, Sseq, subsMat);
	for (int i = 1; i < m; i++)
	{
		result[i][0] = result[0][0]+gap * i;
	}
	for (int i = 1; i < n; i++)
	{
		result[0][i] = result[0][0]+gap * i;
	}
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{
			result[i][j] = max(max(result[i-1][j-1]+score(i, j, Fseq, Sseq, subsMat), result[i-1][j] + gap), result[i][j-1]+gap);
		}
	return result;
}

int** optimumPath(int i, int j, char* Fseq, char* Sseq, int** subsMat)
{
	int size1 = i, size2 = j;
	char **matrix;
	matrix = new char* [i+1];
	for(int index=0; index < i+1;index++)
	{
		matrix[index] = new char[j+1];
	}
	for (int index = 1; index < i+1; index++)
		for (int index2 = 1; index2 < j+1; index2++)
		{
			matrix[index][index2] = '0';
		}
	for (int index = 1; index < i+1; index++)
		matrix[index][0] = Fseq[index-1];
	for (int index = 1; index < j+1; index++)
		matrix[0][index] = Sseq[index-1];
	matrix[i][j] = '1';
	matrix[0][0] = ' ';
	matrix[1][1] = '1';
	int **scoreboard;
	scoreboard = new int* [i];
	for (int index = 0; index < i; index++)
		scoreboard[index] = new int[j];
	scoreboard = scoreMat(i, j, Fseq, Sseq, subsMat);
	cout << endl;
	while (i > 1 || j > 1)
	{
		if (i > 1 && j > 1)
		{
			if (scoreboard[i-1][j-1] == scoreboard[i-2][j-1]+gap)
			{
				matrix[i-1][j] = '1';
				i--;
			}
			else if (scoreboard[i-1][j-1] == scoreboard[i-2][j-2]+score(i-1,j-1, Fseq, Sseq, subsMat))
			{
				matrix[i-1][j-1] = '1';
				i--;
				j--;
			}
			else if (scoreboard[i-1][j-1] == scoreboard[i-1][j-2]+gap)
			{
				matrix[i][j-1] = '1';
				j--;
			}
		}
		else if (i > 1)
		{
			matrix[i][1] = '1';
			i--;
		}
		else  if (j > 1)
		{
			matrix[1][j] = '1';
			j--;
		}
	}
	cout << "Optimum Path is: \n" << endl;
	for (int index = 0; index < size1+1; index++)
	{
		for (int index2 = 0; index2 < size2+1; index2++)
		{
			cout << matrix[index][index2] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	int **result;
	result = new int* [size1];
	for(int index=0; index < size1;index++)
	{
		result[index] = new int[size2];
	}
	for (int index = 0; index < size1; index++)
		for (int index2 = 0; index2 < size2; index2++)
		{
			result[index][index2] = 0;
		}
	for (int index = 1; index < size1+1; index++)
	{
		for (int index2 = 1; index2 < size2+1; index2++)
		{
			if (matrix[index][index2] == '1')
				result[index-1][index2-1] = 1;
		}
	}
	return result;
}

void printAlignment(int size1, int size2, int** matrix, char* Fseq, char* Sseq)
{
	cout << "Optimum Alignment is: \n";
	int count = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (matrix[i][j] == 1)
			{
				if (count == 0)
					cout << Fseq[i];
				else
					cout << '-';
				count++;
			}
		}
		count = 0;
	}
	cout << endl;
	for (int i = 0; i < size2; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			if (matrix[j][i] == 1)
			{
				if (count == 0)
					cout << Sseq[i];
				else
					cout << '-';
				count++;
			}
		}
		count = 0;
	}
	cout << "\n\n";
}

int** getSubMat(string address)
{
	int* list;
	int value;
	int size = 0;
	ifstream readFile;
	readFile.open(address);
	if (readFile.is_open())
	{
		while(readFile >> value)
		{
			size++;
		}
	}
	else
	{
		cout << "unable to open file at " << address << endl;
	}
	readFile.close();
	list = new int[size];
	size = 0;
	readFile.open(address);
	if (readFile.is_open())
	{
		while(readFile >> value)
		{
			list[size] = value;
			size++;
		}
	}
	else
	{
		cout << "unable to open file at " << address << endl;
	}
	int **subsMat;
	double len = sqrt(double(size));
	subsMat = new int* [int(len)];
	for(int index=0; index < int(len);index++)
	{
		subsMat[index] = new int[int(len)];
	}
	int index = 0;
	for (int row = 0; row < len; row++)
	{
		for (int col = 0; col < len; col++)
		{
			subsMat[row][col] = list[index];
			index++;
		}
	}
	return subsMat;
}



int main()
{
	int size1=0, size2=0;
	string adSeq1, adSeq2, adSubMat, dummyLine;
	cout << "Address of the Sequence #1: ";
	cin >> adSeq1;
	cout << "Address of the Sequence #2: ";
	cin >> adSeq2;
	cout << "Address of the substitution matrix: ";
	cin >> adSubMat;
	ifstream myfile(adSeq1);
	char temp;
	if (myfile.is_open())
	{
		getline(myfile, dummyLine);
		while (myfile >> temp)
		{
			size1++;
		}
		myfile.close();
	}
	else
		cout << "Unable to open file.";
	char* Fseq = new char[size1+1];
	ifstream myfile2(adSeq1);
	if (myfile2.is_open())
	{
		int i = 0;
		getline(myfile2, dummyLine);
		while (myfile2 >> temp)
		{
			Fseq[i] = temp;
			i++;
		}
		myfile2.close();
	}
	else
		cout << "Unable to open file.";
	Fseq[size1] = '\0';

	ifstream myFile(adSeq2);
	if (myFile.is_open())
	{
		getline(myFile, dummyLine);
		while (myFile >> temp)
		{
			size2++;
		}
		myFile.close();
	}
	else
		cout << "Unable to open file.";
	char* Sseq = new char[size2+1];
	Sseq[size2] = '\0';
	ifstream myFile2(adSeq2);
	if (myFile2.is_open())
	{
		int i = 0;
		getline(myFile2, dummyLine);
		while (myFile2 >> temp)
		{
			Sseq[i] = temp;
			i++;
		}
		myFile2.close();
	}
	else
		cout << "Unable to open file.";

	printAlignment(size1, size2, optimumPath(size1, size2, Fseq, Sseq, getSubMat(adSubMat)), Fseq, Sseq);
	cout << "Optimum Alignment Score is: " << scoreMat(size1, size2, Fseq, Sseq, getSubMat(adSubMat))[size1-1][size2-1] << endl;
	return 0;
}