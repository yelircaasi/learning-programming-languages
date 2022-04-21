#include <iostream>
#include <string>
#include <tuple>
using std::tuple; using std::cout; using std::string;

int main() {
    tuple<int,string> a { 12, "gnorf" };
    tuple b { 666 };
    tuple<double,double,string> c { 77.77, 33.33, "frong" };
    tuple<int,string,int,double,double,string> r = std::tuple_cat( a, b, c );
    cout << std::get<2>(r) << "\n"; // Ausgabe: 666
}

