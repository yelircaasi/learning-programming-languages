#include <iostream>

int main() {
    int carray[10] = { 1,1 };               // initialisiert zu { 1,1,0,0,0,0,0,0,0,0 }
    int* ende = carray+10;                  // Zeiger  hinter das letzte Element

    for(int* p =carray+2; p != ende; ++p) {
        *p = *(p-1) + *(p-2);               // addiert die vorigen beiden Zahlen
    }

    for(int const * p=carray; p != ende; ++p)
        std::cout << *p << " ";
    std::cout << "\n";
}

