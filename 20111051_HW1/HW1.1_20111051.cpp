#include  <iostream> 
#define  SWAP(x,y,t)  ((t)  =  (x),  (x)=  (y),  (y) = (t))
using namespace std;

void  perm(char  *list,  int  i,  int  n) 
{
	int temp;
	if (i  ==  n)
	{ 
		for  (int j  =  0;  j  <=  n;  j++) 
		cout << list[j] << "  ";
	}
	else
	{ 
		for  (int j  =  i;  j  <=  n;  j++)
		{ 
			SWAP(list[i],list[j],temp); 
			perm(list,i+1,n); 
			SWAP(list[i],list[j],temp);
		}
	}
}

int main()
{
	char a[3] = {'a', 'b', 'c'};
	perm(a, 0, 2);
}