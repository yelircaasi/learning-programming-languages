#include <fstream>
#include <iomanip> // setw
#include <iostream>
int main() {
    std::ifstream file("data.dat");
    if( !file ) {
        std::cout << "Fehler beim Öffnen\n";
        return 1;
    }
    char ch;
    while(file.get(ch) ) {
        std::cout.put(ch);
    }
    if( file.eof() ) {
        file.clear();
    }
    file.close();
}

