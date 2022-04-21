#include <string>
#include <iostream>
using std::string; using std::cout;
struct Person {
    string name_;
    int alter_;
    string ort_;
    void drucke();      // Funktion als Methode des Typs
};
void Person::drucke() { // Name der Methode wird um Person:: erweitert
    cout << name_       // in einer Methode können Sie direkt auf Felder zugreifen
        << " ("<< alter_<<") aus " << ort_ << "\n";
}
int main() {
    Person otto {"Otto", 45, "Kassel" };
    otto.drucke();      // Aufruf der Methode für eine Variable des Typs
}

