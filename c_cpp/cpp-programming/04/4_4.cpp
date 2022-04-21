//4_4.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Point                     //definition of class Point
{
    public:
        Point(int xx=0, int yy=0) {X=xx;Y=yy;}
        Point(Point &p);
        int GetX() {return X;}
        int GetY() {return Y;}
    private:
        int X,Y;
};

Point::Point(Point &p)          //implementation of copy constructor
{
    X=p.X;
    Y=p.Y;
    cout<<"Copy constructor of Point is called"<<endl;
}

//combination of class
class Line                      //definition of class Line
{
    public:                     //external interface
        Line (Point xp1, Point xp2);
        Line (Line &);
        double GetLen(){return len;}
    private:                    //private data members
        Point p1,p2;            //objects p1 p2 of class Point
        double len;
};

//constructor of combine class
Line:: Line (Point xp1, Point xp2)
:p1(xp1),p2(xp2)
{
    cout<<"Constructor of Line is called"<<endl;
    double x=double(p1.GetX()-p2.GetX());
    double y=double(p1.GetY()-p2.GetY());
    len=sqrt(x*x+y*y);
}

//Copy constructor of combine class
Line:: Line (Line &L): p1(L.p1), p2(L.p2)
{
    cout<<"Copy constructor of Line is called"<<endl;
    len=Seg.len;
}

//main function
int main()
{
    Point myp1(1,1),myp2(4,5);       //create object of class Point
    Line line(myp1,myp2);            //create object of class Line
    Line line2(line);                //create a new object using copy
                                     //constructor
    cout<<"The length of the line is:";
    cout<<line.GetLen()<<endl;
    cout<<"The length of the line2 is:";
    cout<<line2.GetLen()<<endl;
}
