#include <iostream>
#include <string>
using namespace std; 
#define Pi 3.1415

int main ()
{
	const double a = 25.0;
	double b;
	cout << "What is the length of b?" << endl;
	cin >> b;
	double area = Pi * a * b;
	cout << "Area: " << area << endl;
	return 0;
}