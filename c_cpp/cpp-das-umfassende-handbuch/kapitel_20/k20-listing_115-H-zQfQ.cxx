#include <string>
#include <iostream>                    // cout
using std::string; using std::cout;
string greet(string name) {
    return name + "!";                 // string operator+(string, const char*)
}

int main() {
    string name{ "Havaloc Vetinari" }; // explizit: string(const char*)
    cout << "Angua";                   // ostream& operator<<(ostream&, const char*)
    cout <<                            // ostream& operator<<(ostream&, string)
      greet("Carrot Ironfoundersson"); // implizit: string(const char*)
}

