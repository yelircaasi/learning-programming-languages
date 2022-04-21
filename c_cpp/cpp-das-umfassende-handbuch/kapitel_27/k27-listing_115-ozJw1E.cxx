#include <fstream>
#include <iostream>
using std::cout;
int main() {
    std::ofstream file01("testfile.txt", std::ios::out|std::ios::app);
    if(file01.fail()) {
        cout << "Konnte testfile.txt nicht öffnen\n";
    } else {
        cout << "ok.\n";
    }

    std::fstream file02;
    file02.open("database.db", std::ios::out|std::ios::trunc);
    if( !file02 ) {
        cout << "Konnte database.db nicht öffnen\n";
    } else {
        cout << "ok.\n";
    }
}

