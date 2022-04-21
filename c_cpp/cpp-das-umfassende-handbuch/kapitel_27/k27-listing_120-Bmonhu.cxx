#include <fstream>
#include <iostream>
using std::cout;

int main() {
    std::ifstream file("44fstream07.cpp");
    if( !file ) { /* Fehler */ cout << "ERR\n"; return 1; }
    std::ofstream filecopy("backup.cpp");
    if( !filecopy ) { /* Fehler */ cout << "ERR\n"; return 1; }

    std::string puffer;
    while( getline(file, puffer) ) {
        filecopy << puffer << std::endl;
        cout << puffer << std::endl;
    }
    if( file.eof() ) {
        file.clear();
    }
}

