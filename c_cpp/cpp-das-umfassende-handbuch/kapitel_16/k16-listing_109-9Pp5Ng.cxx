struct MeinWert {
   static int zaehler;
   int nummer_;
   string name_;
   explicit MeinWert(string name) // wie zuvor
      : nummer_{++zaehler} , name_{name}
      { cout << setw(nummer_) << '_'  << "Konstruktor " << name_ << "\n"; }
   MeinWert(const MeinWert &orig) // neuer Kopierkonstruktor
      : nummer_{++zaehler} , name_{orig.name_ + "-Kopie"}
      { cout << setw(nummer_)<<" " << "Kopierkonstruktor " << name_ << "\n"; }
   ~MeinWert() { // wie zuvor
      cout << setw(nummer_)<<" " << "Destruktor " << name_ << "\n";
   }
};
int MeinWert::zaehler = 0;

