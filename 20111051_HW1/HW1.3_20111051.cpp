#include <iostream>
#define MAX_COL 101
using namespace std;

typedef struct {
	int col;
	int row;
	int value;
} term;


void fastTranspose(term a[],  term  b[])
{
	int rowTerms[MAX_COL];
	int startingPos[MAX_COL];
	int index;
	int numCols = a[0].col;
	int numTerms = a[0].value;
	b[0].row = numCols;
	b[0].col = a[0].row; 
	b[0].value = numTerms;
	if  (numTerms > 0)
	{
		for (int i = 0; i < numCols; i++) 
			rowTerms[i] = 0; 
		for (int i = 1; i <= numTerms; i++) 
			rowTerms[a[i].col]++;
		startingPos[0] = 1;
		for (int i = 1; i < numCols; i++) 
			startingPos[i] = startingPos[i-1] + rowTerms[i-1];
		for (int i = 1; i <= numTerms; i++)
		{
			index = startingPos[a[i].col]++;
			b[index].row = a [i].col;
			b[index].col = a [i].row; 
			b[index].value = a[i].value; 
		}
	}
}

int main()
{
	term a[9], b[9];
	a[0].col = 6;
	a[0].row = 6;
	a[0].value = 8;
	a[1].col = 0;
	a[1].row = 0;
	a[1].value = 15;
	a[2].col = 3;
	a[2].row = 0;
	a[2].value = 22;
	a[3].col = 5;
	a[3].row = 0;
	a[3].value = -15;
	a[4].col = 1;
	a[4].row = 1;
	a[4].value = 11;
	a[5].col = 2;
	a[5].row = 1;
	a[5].value = 3;
	a[6].col = 3;
	a[6].row = 2;
	a[6].value = -6;
	a[7].col = 0;
	a[7].row = 4;
	a[7].value = 91;
	a[8].col = 2;
	a[8].row = 5;
	a[8].value = 28;
	fastTranspose(a, b);
	cout << "Row\tCol\tValue\n";
	cout << a[0].row << "\t" << a[0].col << "\t" << a[0].value << "\n";
	for (int i = 1; i < 9; i++)
	{
		cout << a[i].row << "\t" << a[i].col << "\t" << a[i].value << "\n";
	}
	cout << "\n\nRow\tCol\tValue\n";
	cout << b[0].row << "\t" << b[0].col << "\t" << b[0].value << "\n";
	for (int i = 1; i < 9; i++)
	{
		cout << b[i].row << "\t" << b[i].col << "\t" << b[i].value << "\n";
	}
}