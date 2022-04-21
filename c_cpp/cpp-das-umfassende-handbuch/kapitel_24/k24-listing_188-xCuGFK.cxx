#include <vector>
#include <string>
#include <iostream>
using std::string; using std::vector; using std::cout;

int main() {
    string s1 = "Hallo";                  // einfach mit String-Literal
    string s2{@'@H@'@,@'@a@'@,@'@l@'@,@'@l@'@,@'@o@'@};       // oder mit Liste von char

    using namespace std::literals;        // für ""s-Suffix
    auto s3 = "Hallo"s;  // noch einfacher mit echtem String-Literal

    vector<char> v1{"Hallo"};             // kein vector mit String-Literal
    vector<char> v2{@'@H@'@,@'@a@'@,@'@l@'@,@'@l@'@,@'@o@'@}; // Liste von char ist okay
    cout << s1 << s2 << s3 << '\n';       // Ausgabe von string geht
    cout << v1 << v2 << '\n';             // vector hat keine Ausgabe
}

