// Problem02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string text;
	int start;
	int end;
	cout << "Text?" << endl;
	getline (cin, text);
	cout << "Start?" << endl;
	cin >> start;
	cout << "End?" << endl;
	cin >> end;
	string result = text.substr(start-1, end-start+1);
	cout << "Result: " << result << endl;
	return 0;
}

