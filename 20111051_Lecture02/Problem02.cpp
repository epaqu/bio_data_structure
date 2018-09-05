
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
	srand(time(0));
	int a, b, c, d, input, w, x, y, z;
	a=rand()%9+1;
	b=rand()%9+1;
	c=rand()%9+1;
	d=rand()%9+1;
	while (a==b || a==c || a==d || b==c || b==d  || c==d)
	{
		a=rand()%9+1;
		b=rand()%9+1;
		c=rand()%9+1;
		d=rand()%9+1;
	}
	while(true)
	{
		cout << "enter a number: " << endl;
		cin >> input;
		w = input/1000;
		x = (input%1000) / 100;
		y = ((input%1000) % 100) / 10;
		z = ((input%1000) % 100) % 10;
		int numStrike=0, numBall=0;
		if (a==w)
		{
			numStrike++;
		}
		if (b==x)
		{
			numStrike++;
		}
		if (c==y)
		{
			numStrike++;
		}
		if (d==z)
		{
			numStrike++;
		}
		if (a==x || a==y || a==z)
		{
			numBall++;
		}
		if (b==y || b==z || b==w)
		{
			numBall++;
		}
		if (c==z || c==w || c==x)
		{
			numBall++;
		}
		if (d==y || d==w || d==x)
		{
			numBall++;
		}
		cout << numStrike << " strike(s) " << numBall << " ball(s)" << endl;
	}
	return 0;
}
