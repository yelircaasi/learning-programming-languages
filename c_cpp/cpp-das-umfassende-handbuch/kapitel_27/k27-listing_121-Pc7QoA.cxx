#include <fstream>
#include <iostream>
#include <vector>
using std::cout;
int main() {
    std::ifstream file("testfile.txt", std::ios::binary);
    if( !file ) { /* Fehler */ cout <<"ERR1\n"; return 1; }
    std::ofstream filecopy("backup.dat", std::ios::binary);
    if( !filecopy ) { /* Fehler */ return 1; }
    file.seekg(0, std::ios::end);
    auto size = file.tellg();
    cout << "Dateigroesse : " << size << " Byte\n";
    file.seekg(0, std::ios::beg); // Wichtig!
    std::vector<char> puffer(size);
    file.read(puffer.data(), size);
    if( !file ) { cout << "Fehler bei read...\n"; return 1;}
    cout << "Gelesen: " << file.gcount() << " Byte\n";
    filecopy.write( puffer.data(), size );
    if( !filecopy ) { cout << "Fehler bei write...\n"; return 1;}
}

