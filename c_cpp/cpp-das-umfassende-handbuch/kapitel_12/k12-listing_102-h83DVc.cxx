// Ausschnitt
Person erzeuge(string name, int alter, string ort) {
    return Person{name, alter, ort};       // direkt zurückgegeben
}
int main() {
    drucke(erzeuge("Otto", 45, "Kassel")); // Rückgabe direkt verwendet
}

