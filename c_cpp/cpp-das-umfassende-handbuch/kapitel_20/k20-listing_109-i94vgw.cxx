#include <iostream>
void fibonacci(int data[], int* ende) {
    for(int* p = data+2; p != ende; ++p) {
        *p = *(p-1) + *(p-2);
    }
}
std::ostream& print(std::ostream &os, int data[], int* ende) {
    for(int const * p=data; p != ende; ++p)
        std::cout << *p << " ";
    return os;
}
int main() {
    int carray[10] = { 1,1 }; // initialisiert zu { 1,1,0,0,0,0,0,0,0,0 }
    fibonacci(carray, carray+10);
    print(std::cout, carray, carray+10) << "\n";
}

