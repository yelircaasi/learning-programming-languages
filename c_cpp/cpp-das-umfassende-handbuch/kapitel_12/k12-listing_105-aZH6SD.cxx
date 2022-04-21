int wert = 5;                         // globale Variable
struct Wrap {
    int wert = 3;                     // Datenfeld
    void setze(int wert) {            // Parameter
        this->wert = wert + ::wert;
    }
};

