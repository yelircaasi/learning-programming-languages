//2_10.cpp
#include<iostream>
using namespace std;
int main()
{
	int i=0, j=0, n;
	cout << " Please enter a series of numbers (enter 0 to end): \n";
	cin >> n;
	while( n!=0 )
	{
		if(n>0) i+=1;
		if(n<0) j+=1;
		cin >> n;
	}
	cout << "The number of positive integers: " << i << "\nThe number of negative integers: " << j << endl;
}
