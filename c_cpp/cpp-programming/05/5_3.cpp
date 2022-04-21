//5_3.cpp
#include<iostream>
using namespace std;
class Clock
//class clock definition
{
    public:             //external interface
        Clock();
        void SetTime(int NewH, int NewM, int NewS);
                        //all the three parameters have function prototype scope
        void ShowTime();
        ~Clock(){}
    private:                        //private data member
    int Hour,Minute,Second;
};

//realize class Clock member function
Clock::Clock()                      //constructor
{
    Hour=0;
    Minute=0;
    Second=0;
}

void Clock::SetTime(int NewH, int NewM, int NewS)
{
    Hour=NewH;
    Minute=NewM;
    Second=NewS;
}

void Clock::ShowTime()
{
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

Clock globClock;                    //declare object globClock , which has static
                                    //lifetime, file scope
                                    //use default constructor to initialize it to 0:0:0

int main()                          //main function
{
    cout<<"First time output:"<<endl;
    //quote object globClock that has file scope
    globClock.ShowTime();           //the member function of object has     
                                    //class scope
                                    //display 0:0:0
    globClock.SetTime(8,30,30);     //set the time to 8:30:30
    Clock myClock(globClock);       //declare object myClock that has
                                    //local scope
                                    //call copy constructor, initialize
                                    //it by globClock
    cout<<"Second time output:"<<endl;
    myClock.ShowTime();             //reference object myClock that has     
                                    //local scope
                                    //output 8:30:30
}
