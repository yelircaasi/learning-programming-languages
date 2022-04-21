//4_1.cpp
#include<iostream>
using namespace std;
class Clock                 //definition of class Clock
{
    public:                 //exterior interface, public function member
    void SetTime(int NewH=0, int NewM=0, int NewS=0);
    void ShowTime();
    private:                //private data member
    int Hour,Minute,Second;
};

//implementation of function member of class Clock
void Clock::SetTime(int NewH, int NewM, int NewS)
{
    Hour=NewH;
    Minute=NewM;
    Second=NewS;
}

inline void Clock::ShowTime()
{
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

//main function
int main()
{
    Clock myClock;                  //define object myClock
    cout<<"First time set and output:"<<endl;
    myClock.SetTime();              //set time to default value
    myClock.ShowTime();             //show time
    cout<<"Second time set and output:"<<endl;
    myClock.SetTime(8,30,30);       //set time to 8:30:30
    myClock.ShowTime();             //show time
}
