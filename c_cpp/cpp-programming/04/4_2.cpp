//4_2.cpp
#include <iostream>
using namespace std;

class Point                            //Definition of class Point
{
    public:                                //external interface
        Point(int xx=0, int yy=0) {X=xx;Y=yy;} //constructor
        Point(Point &p);                       //copy constructor
        int GetX() {return X;}
        int GetY() {return Y;}
    private:                               //private data
        int X,Y;
};

//implementations of member functions
Point::Point(Point &p)
{
    X=p.X;
    Y=p.Y;
    cout<<"copy constructor is called"<<endl;
}

//a function with an object of class Point as parameter
void fun1(Point p)
{ 
    cout<<p.GetX()<<endl;
}

//a function with an object of class Point as return value
Point fun2()
{
    Point A(1,2);
    return A;
}

//main function
int main()
{
    Point A(4,5);                   //first object A
    Point B(A);                     //situation one, use A to initialize B . First time to
                                    //call copy constructor
    cout<<B.GetX()<<endl;
    fun1(B);                        //situation two, use object B as the formal parameter of
                                    // fun1 . Second time to call copy constructor
    B=fun2();                       //situation three, the return value of the function is
                                    //an object. Call copy constructor when returning to
                                    //the main function
    cout<<B.GetX()<<endl;
}
