//3_7.cpp
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    int fun1(int x,int y);
    cin>>a>>b;
    cout<<"Sum of squares of a and b:"<<fun1(a,b)<<endl;
}

int fun1(int x,int y)
{
    int fun2(int m);
    return (fun2(x)+fun2(y));
}

int fun2(int m)
{
    return (m*m);
}
