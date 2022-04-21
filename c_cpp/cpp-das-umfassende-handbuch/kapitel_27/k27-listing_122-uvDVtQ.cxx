#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::string;

class DataClass {
    std::string text_;
    int data_;
public:
    DataClass(string t="", int i=0)
      : text_{t}, data_{i} {}

    std::ostream& write(std::ostream& os) const {
        os << text_ << std::ends;
        os.write(reinterpret_cast<const char*>(&data_), sizeof(data_));
        return os;
    }
    std::istream& read(std::istream& is) {
        std::getline(is, text_, '\0');
        is.read(reinterpret_cast<char*>(&data_), sizeof(data_));
        return is;
    }
    std::ostream& print(std::ostream& os) {
        return os << text_ << " : " << data_ << std::endl;
    }
};
int main() {
    std::ofstream file_w("data.dat", std::ios::binary);
    if( !file_w) { cout << "Fehler bei Öffnen\n"; return 1; }

    std::vector<DataClass> vec_dat;
    vec_dat.push_back(DataClass("Ein Text", 123));
    vec_dat.push_back(DataClass("Mehr Text", 321));
    vec_dat.emplace_back("Viel mehr Text", 333);
    for(const auto &elem : vec_dat){
        elem.write(file_w);
    }
    file_w.close();

    std::ifstream file_r("data.dat", std::ios::binary);
    if( !file_r) { cout << "Fehler bei Öffnen\n"; return 1; }
    DataClass dat_r;
    while( file_r ) {
        dat_r.read(file_r);
        if( file_r.eof()) break;
        dat_r.print(cout);
    }
}

