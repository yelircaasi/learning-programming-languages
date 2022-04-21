//... Basis2 und Wert2 wie gehabt ...
void ausgabe(Basis2& x) {       // Übergabe als Referenz
    x.print(cout);
}

int main() {
    Basis2 ba2{}; ausgabe(ba2); // gibt 8 aus
    Wert2 we2{}; ausgabe(we2);  // gibt 10 aus, denn das Objekt wird nicht kopiert
}

