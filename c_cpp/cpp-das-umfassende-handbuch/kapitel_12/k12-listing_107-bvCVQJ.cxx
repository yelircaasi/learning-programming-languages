// Ausschnitt ...
    std::ostream& drucke(std::ostream& os);
};
std::ostream& Person::drucke(std::ostream& os) {
    return os << name_ << " ("<< alter_<<") aus " << ort_;
}
std::ostream& operator<<(std::ostream& os, Person p) {
    return p.drucke(os);
}
int main() {
    Person paul {"Paul", 23, "Dresden"};
    cout << "Sie sind " << paul << ", richtig?\n";
}

