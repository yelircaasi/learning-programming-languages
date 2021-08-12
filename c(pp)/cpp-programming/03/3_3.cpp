//3_3.cpp
#include<iostream>
using namespace std;
int main()
{
	double a, b;
	double arctan(double x);
	a=16.0*arctan(1/5.0);
	b=4.0*arctan(1/239.0);
	//Note: Since the division of integers is to be rounded off, the
	//value of 1/5 and 1/239 are both 0.
	cout<<"PI="<<a-b<<endl;
}
double arctan(double x)
{
	int i;
	double r, e, f, sqr;
	sqr=x*x;
	r=0;
	e=x;
	i=1;
	while(e/i>1e-15)
	{
		f=e/i;
		r=(i%4==1)? r+f : r-f;
		e=e*sqr;
		i+=2;
	}
	return r;
}
