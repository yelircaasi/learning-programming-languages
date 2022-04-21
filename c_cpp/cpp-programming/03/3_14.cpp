//3_14.cpp
#include<iostream>
using namespace std;

inline double CalArea(double radius) //Inline function, to calculate
                                     //the area of a circle
{
    return 3.14*radius*radius;
}

int main()
{
    double r(3.0);      //r is the radius if the circle
    double area;
    area=CalArea(r);
    /*Call inline function to calculate the area of the circle. This
    will be replaced by the body of function CalArea during the
    compiling.*/
    cout<<area<<endl;
}
