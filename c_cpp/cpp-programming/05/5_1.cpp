//5_1.cpp
//examples of scope and visibility
#include <iostream>
using namespace std;

int i;                          //global variable, file scope
int main()
{
    i=5;                        //initialize i if the file scope
    {                           //subblock 1
        int i;                  //local variable, local scope
        i=7;
        cout<<"i="<<i<<endl;    //output 7
    }
    cout<<"i="<<i<<endl;        //output 5
}
