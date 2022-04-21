// Ausschnitt
Person erzeuge(string name, int alter, string ort) { // Rückgabetyp
    Person result {name, alter, ort};
    return result;
}
int main() {
    Person otto = erzeuge("Otto", 45, "Kassel");     // Rückgabe speichern
    drucke(otto);
}

