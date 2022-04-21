//4_3.cpp
#include <iostream>
using namespace std;
const float PI = (float)3.14159;         //give value of p
const float FencePrice = 35.;            //unit price of the fence
const float ConcretePrice = 20.;         //unit price of the concrete for the
                                         //aisle
class Circle
//define Circle and data & function member
{
    public:                             //external interface
        Circle(float r);                //constructor
        float Circumference();          //compute the circumference of the circle
        float Area();                   //compute the area of the circle
    private:                            //private data member
        float radius;
};

//Implementation of class
Circle::Circle(float r) { radius=r; } //constructor initializes data
                                      //member radius

float Circle::Circumference()         //compute the circumference of the
{                                     //circle
    return 2 * PI * radius;
}

float Circle::Area()                  //compute the area of the circle
{
    return PI * radius * radius;
}

//main function
void main ()
{
    float radius;
    float FenceCost, ConcreteCost;
    cout << "Enter the radius of the pool: "; //ask user to enter the
                                              //radius value
    cin >> radius;
    Circle Pool(radius);                      //define objects of Circle
    Circle PoolRim(radius + 3);
    //compute the cost of fence and output it
    FenceCost = PoolRim.Circumference() * FencePrice;
    cout << "Fencing Cost is ¥" << FenceCost << endl;
    //compute the cost of aisle and output it
    ConcreteCost = (PoolRim.Area() - Pool.Area())*ConcretePrice;
    cout << "Concrete Cost is $" << ConcreteCost << endl;
}
