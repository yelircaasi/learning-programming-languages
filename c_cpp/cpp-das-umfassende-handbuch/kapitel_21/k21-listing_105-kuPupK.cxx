#include <iostream>

#define MAX2(a,b) ((a) > (b) ? (a) : (b))

int main() {
    int x = 0;
    int y = 0;
    int z = MAX2( ++x, ++y );
    std::cout << "x:"<< x << " y:"<< y << " z:"<<z << '\n';
}

