//... Basis2 und Wert2 wie gehabt ...
void ausgabe(Wert2 x) {         // abgeleitete Klasse als Wert
    x.print(cout);
}

int main() {
    Basis2 ba2{}; ausgabe(ba2); // ba2 kann nicht in Wert2 umgewandelt werden
    Wert2 we2{}; ausgabe(we2);  // gibt 10 aus
}

