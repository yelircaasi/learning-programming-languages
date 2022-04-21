#include <filesystem>   // std::filesystem
#include <iostream>
namespace fs = std::filesystem; using std::cout; using std::endl;
int main() {
    // Pfadkomponenten
    fs::path root {"/"};
    fs::path dir {"var/www/"};
    fs::path index {"index.html"};
    // zusammenfügen
    fs::path p = root / dir / index;     // operator/
    // ausgeben
    cout << "Name: " << p << endl;       // "/var/www/index.html"
    // zerlegen
    cout << "Vater: " << p.parent_path() << endl; // "/var/www"
    cout << "Name: " << p.filename() << endl;     // "index.html"
    cout << "Endung: " << p.extension() << endl;  // ".html"
    // Information
    cout << std::boolalpha;
    cout << "Existiert? " << fs::exists(p) << endl;
    cout << "Echte Datei? " << fs::is_regular_file(p) << endl;
}

