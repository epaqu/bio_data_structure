#include <iostream>
#include <string>
using namespace std;

int size = 0;
int firstOrSecond = 1;

int **getEquation()
{
	int **equation;
	int **temp;
	int term = 1;
	int order, coefficient;
	cout << "If you want to stop, please enter -1 for order.";
	if (firstOrSecond == 1)
		cout << "\nEnter the first polynomial.";
	else if (firstOrSecond == 2)
		cout << "\nNow enter your second polynomial.";
	cout << "\nPlease enter the order of Term #" << term << ": ";
	cin >> order;
	equation = new int*[2];
	temp = new int*[2];
	if (order != -1)
	{
		for (int i = 0; i < term; i++)
		{
			equation[0] = new int[i];
			equation[1] = new int[i];
			temp[0] = new int[i];
			temp[1] = new int[i];
		}
		cout << "\nPlease enter the coefficient of Term #" << term << ": ";
		cin >> coefficient;
		equation[0][0] = coefficient;
		equation[1][0] = order;
		term++;
		while(true)
		{
			cout << "\nPlease enter the order of Term #" << term << ": ";
			cin >> order;
			if (order == -1)
				break;
			cout << "\nPlease enter the coefficient of Term #" << term << ": ";
			cin >> coefficient;
			for (int i = 0; i < term-1; i++)
			{
				temp[0][i] = equation[0][i];
				temp[1][i] = equation[1][i];
			}
			for (int i = 0; i < term; i++)
			{
				equation[0] = new int[i];
				equation[1] = new int[i];
			}
			for (int i = 0; i < term-1; i++)
			{
				equation[0][i] = temp[0][i];
				equation[1][i] = temp[1][i];
			}
			equation[0][term-1] = coefficient;
			equation[1][term-1] = order;
			for (int i = 0; i < term; i++)
			{
				temp[0] = new int[i];
				temp[1] = new int[i];
			}
			term++;
		}
	}
	size = term;
	return equation;
}

void printEquation(int term, int **equation)
{
	if (firstOrSecond == 1)
		cout << "Your first polynomial is: ";
	else if (firstOrSecond == 2)
		cout << "Your second polynomial is: ";
	else
		cout << "The multiplication of the two polynomials are: ";
	if (term == 1)
		cout << "" << endl;
	else
	{
		for (int i = 0; i < term-2; i++)
		{
			if (equation[0][i] != 1 && equation[0][i] != 0)
				if (equation[1][i] != 1 && equation[1][i] != 0)
					cout << equation[0][i] << "x^" << equation[1][i] << " + ";
				else if (equation[1][i] == 1)
					cout << equation[0][i] << "x" << " + ";
				else if (equation[1][i] == 0)
					cout << equation[0][i] << " + ";
			else
				if (equation[1][i] != 1 && equation[1][i] != 0)
					cout << "x^" << equation[1][i] << " + ";
				else if (equation[1][i] == 1)
					cout << "x" << " + ";
				else if (equation[1][i] == 0)
					cout << " + ";
		}
		if (equation[0][term-2] != 1)
			if (equation[1][term-2] != 1 && equation[1][term-2] != 0)
				cout << equation[0][term-2] << "x^" << equation[1][term-2];
			else if (equation[1][term-2] == 1)
				cout << equation[0][term-2] << "x";
			else if (equation[1][term-2] == 0)
				cout << equation[0][term-2];
		else
			if (equation[1][term-2] != 1 && equation[1][term-2] != 0)
				cout << "x^" << equation[1][term-2];
			else if (equation[1][term-2] == 1)
				cout << "x";	
		cout << endl;
		cout << endl;
		cout << endl;
	}
}

int **sortDecreasing(int **equation, int size)
{
	int largest, id;
	for (int i = 0; i< size; i++)
	{
		largest = equation[1][i];
		id = equation[0][i];
		for (int j = i; j < size; j++)
		{
			if (largest < equation[1][j])
			{
				largest = equation[1][j];
				equation[1][j] = equation[1][i];
				equation[1][i] = largest;
				id = equation[0][j];
				equation[0][j] = equation[0][i];
				equation[0][i] = id;
			}
		}
	}
	return equation;
}

int main()
{
	int **equation1 = getEquation();
	int size1 = size;
	printEquation(size1, sortDecreasing(equation1, size1-1));
	firstOrSecond++;
	int **equation2 = getEquation();
	int size2 = size;
	printEquation(size2, sortDecreasing(equation2, size2-1));
	int length = (size1-1) * (size2-1);
	firstOrSecond++;
	//done getting the polynomials
	
	int **multiplied;
	multiplied = new int*[2];
	multiplied[0] = new int[length];
	multiplied[1] = new int[length];
	int index = 0;
	for (int i = 0; i < size1-1; i++)
	{
		for (int j = 0; j < size2-1; j++)
		{
			multiplied[0][index] = equation1[0][i] * equation2[0][j];
			multiplied[1][index] = equation1[1][i] + equation2[1][j];
			index++;
		}
	}
	//done multiplying

	int ind=0, temp;
	for (int i =1; i < length; i++)
	{
		temp = multiplied[1][ind];
		for (int j =i; j < length; j++)
			if (multiplied[1][j] == temp)
			{
				multiplied[0][ind] += multiplied[0][j];
				multiplied[0][j] = 0;
				multiplied[1][j] = 0;
			}
		ind++;
	}
	//done simplifying

	int unnecessary = 0;
	for (int j = 0; j < length; j++)
		if (multiplied[0][j] == 0)
			unnecessary++;
	sortDecreasing(multiplied, length);
	int new_length = length - unnecessary;
	int **result;
	result = new int*[2];
	result[0] = new int[new_length];
	result[1] = new int[new_length];
	
	int index_new = 0;
	for (int i = 0; i < length; i++)
	{
		if (multiplied[0][i] != 0)
		{
			result[0][index_new] = multiplied[0][i];
			result[1][index_new] = multiplied[1][i];
			index_new++;
		}
	}
	printEquation(new_length+1, result);

}