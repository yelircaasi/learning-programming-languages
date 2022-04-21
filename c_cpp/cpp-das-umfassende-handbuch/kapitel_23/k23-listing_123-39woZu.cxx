#include <iostream>
int main() {
    int count = 0;
    auto plus1 = [&count](int x) { // count als Referenz
        ++count; return x+1;
    };
    for(int i=0; i<5; ++i) { plus1(i); }
    std::cout << "plus1 wurde " << count << " mal aufgerufen\n";
    // Ausgabe: plus1 wurde 5 mal aufgerufen
}

