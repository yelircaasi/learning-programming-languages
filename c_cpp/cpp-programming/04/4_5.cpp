//4_5.cpp
#include<iostream>
#include"employee.h"
using namespace std;

int main()
{
    employee m1;
    employee t1;
    employee sm1;
    employee s1;

    cout<<"Please input payment of next employee:";
    float pa;
    cin>> pa;
    m1.IncreaseEmpNo(0);            //set m1 ’s id to current id
    m1.promote(3);                  //m1 promoted by 3 grades
    m1.SetaccumPay (pa);            //set payment of m1
    
    cout<<" Please input payment of next employee:";
    cin>>pa;
    t1.IncreaseEmpNo(1);            //set t1 ’s id to current id plus 1
    t1.promote(2);                  //t1 promoted by 2 grades
    t1.SetaccumPay (pa);            //set payment of t1
    
    cout<<" Please input payment of next employee:";
    cin>> pa;
    sm1.IncreaseEmpNo(2);           //set sm1 ’s id to current id plus 2
    sm1.promote(2);                 //sm1 promoted by 2 grades
    sm1.SetaccumPay (pa);           //set grade of sm1
    
    cout<<" Please input payment of next employee:";
    cin >>pa;
    s1.IncreaseEmpNo(3);            //set s1 ’s id to current id plus 3
    s1.SetaccumPay (pa);            //set payment of s1
    
    //display information of m1
    cout<<"ID"<<m1.GetindividualEmpNo()
        <<" grade is "<<m1.Getgrade()<<",
        payment is "<<m1.GetaccumPay()<<endl;
    
    //display information of t1
    cout<<"ID"<<t1.GetindividualEmpNo()
        <<" grade is "<<t1.Getgrade()<<",
        payment is"<<t1.GetaccumPay()<<endl;
    
    //display information of sm1
    cout<<"ID"<<sm1.GetindividualEmpNo()
        <<" grade is"<<sm1.Getgrade()<<",
        payment is"<<sm1.GetaccumPay()<<endl;
    
    //display information of s1
    cout<<"ID"<<s1.GetindividualEmpNo()
        <<" grade is"<<s1.Getgrade()<<",
        payment is"<<s1.GetaccumPay()<<endl;
}
