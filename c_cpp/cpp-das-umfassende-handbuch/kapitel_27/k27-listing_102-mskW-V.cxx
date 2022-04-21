#include <fstream>
#include <iostream>
using std::cout; using std::cin; using std::ofstream;
void checkIOstate(std::ios& stream) {
    if( stream.good() ) {
        cout << "Alles in Ordnung\n";
    } else if( stream.bad() ) {
        cout << "Fataler Fehler\n";
    } else if( stream.fail()) {
        cout << "Fehler bei der Ein-/Ausgabe\n";
        if( stream.eof()) {
            cout << "Ende des Datenstroms erreicht\n";
        }
    }
    stream.clear();
}
int main() {
    int val=0;
    cout << "Wert eingeben: ";
    cin >> val;
    checkIOstate( cin );
    std::ifstream file;
    file.open("nichtvorhanden.text");
    checkIOstate(file);
    std::fstream fstr;
    fstr.open("neueDatei.txt",
        ofstream::out | ofstream::in
        | ofstream::binary | ofstream::trunc);
    fstr << "Text in der Datei\n";
    fstr.seekp(std::ios_base::beg);
    char ch;
    while( fstr.good()) {
        fstr.get(ch);
        if(fstr.good()) cout.put(ch);
    }
    checkIOstate(fstr);
}

