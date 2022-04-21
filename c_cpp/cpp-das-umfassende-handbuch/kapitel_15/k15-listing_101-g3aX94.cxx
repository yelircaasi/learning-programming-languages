class Year : public Value {               // von Klasse Value ableiten
public:
    explicit Year(int v) : Value{v, 4} {} // Basisklasse initialisieren
};
class Month : public Value {
public:
    explicit Month(int v) : Value{v, 2} {}
};
struct Day : public Value {               // class-public entspricht struct
    explicit Day(int v) : Value{v, 2} {}
};

