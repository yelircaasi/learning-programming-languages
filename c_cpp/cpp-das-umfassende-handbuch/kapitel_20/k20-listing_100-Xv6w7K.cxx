int value = 42;
int& valueRef = value; // Referenz; kein Adressoperator & nötig
valueRef = 18;         // kein Dereferenzierungsoperator * nötig
cout << value << "\n"; // Ausgabe: 18

