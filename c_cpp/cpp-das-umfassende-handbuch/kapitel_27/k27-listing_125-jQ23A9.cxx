#include <sstream> // stringstream
#include <iostream>
#include <stdexcept> // invalid_argument
template <class T1, class T2>
void myConvert(const T1& in, T2& out) {
    std::stringstream ss;
    ss << in;
    ss >> out;
    if( ! ss.eof() ) {
        throw std::invalid_argument("Fehler beim Konvertieren");
    }
}
int main() {
    std::string sval;
    float fval=3.1415f;
    std::string sdval("5.321");
    double dsval=0;
    std::string gehtnicht("geht nicht");
    try {
        myConvert(fval, sval);
        std::cout << sval << std::endl;  // Ausgabe: 3.1415
        myConvert(sdval, dsval);
        std::cout << dsval << std::endl; // Ausgabe: 5.321
        myConvert(gehtnicht, dsval);     // löst "Fehler beim Konvertieren" aus
    }
    catch(const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

