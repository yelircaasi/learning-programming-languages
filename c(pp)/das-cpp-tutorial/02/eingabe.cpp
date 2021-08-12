#include<iostream>

int main(int argc, char**argv)
// Alternativen:
// int main(int argc, char* argv[])
// int main(int a, char** b)

//unsigned main...
//short main...
//long main...
//char main...

//verboten:
//float main...
//double main...
//void main...
{
    using namespace std;

    for(int i = 0; i < argc; ++i)
    {
        cout << i << ": " << argv[i] << endl << endl;
    }

    return 0;
}