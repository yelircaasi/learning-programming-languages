//5_2.cpp
#include<iostream>
using namespace std;
int i=1;                        // i is a global variable with static lifetime
int main()
{ 
    static int a;               // a is a static local variable that has static
                                //lifetime, locally visible
    int b=-10;                      // b, c are local variables that have dynamic
                                //lifetime
    int c=0;
    void other(void);
    cout<<"---MAIN---\n";
    cout<<" i: "<<i<<" a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
    c=c+8; other();
    cout<<"---MAIN---\n";
    cout<<" i: "<<i<<" a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
    i=i+10; other(); }

void other(void)
{
    static int a=2;
    static int b;
    // a,b are static local variables that have global lifetime, locally
    //visible, and only initialized when the function is executed for
    //the first time.
    int c=10;                   //c is a local variable that has dynamic lifetime,
                                //should be initialized every time the function is
                                //executed.
    a=a+2; i=i+32; c=c+5;
    cout<<"---OTHER---\n";
    cout<<" i: "<<i<<" a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
    b=a;
}
