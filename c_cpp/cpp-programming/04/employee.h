//employee.h
class employee
{
    protected:
        int individualEmpNo;            //id
        int grade;                      //grade
        float accumPay;                 //payment
    public:
        employee();                     //constructor
        ~employee();                    //destructor
        void IncreaseEmpNo (int);       //increasing id function
        void promote(int);              //promoting function
        void SetaccumPay (float);       //setting payment function
        int GetindividualEmpNo();       //getting id function
        int Getgrade();                 //getting grade function
        float GetaccumPay();            //getting payment function
};

employee::employee()
{ 
    individualEmpNo=1000;               //max id of employee now is 1000
    grade=1;                            //initial grade is 1
    accumPay=0.0;                       //initial payment is 0
} 

employee::~employee() {}                //destructor is empty

void employee::IncreaseEmpNo (int steps)
{ individualEmpNo+=steps;}              //increase id by steps

void employee::promote(int increment)
{ grade+=increment;}                    //promote grade by increment

void employee::SetaccumPay (float pa)
{ accumPay=pa;}                         //set payment

int employee::GetindividualEmpNo()
{ return individualEmpNo;}              //get member id

int employee::Getgrade()
{ return grade;}                        //get grade

float employee::GetaccumPay()
{ return accumPay;}                     //get payment
