#include <fstream>
#include <iomanip> // setw
#include <iostream>

int main() {
    std::ofstream file("data.dat");
    if( !file ) {
        std::cout << "Konnte data.dat nicht öffnen\n";
        return 1;
    }

    file << std::setw(10) << std::setfill( '*' )
         << 1234 << std::endl;
}

