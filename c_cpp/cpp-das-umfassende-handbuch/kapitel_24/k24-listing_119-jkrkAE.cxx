vector d{ 1, 2, 4, -1, 1, 2, -2 };
for(size_t idx=0; idx < d.size(); ) { // prüft vector-Grenze
    cout << d[idx] << ' ';           // zusätzliche Prüfung mit at nicht nötig
    idx += d[idx];                   // hier ebenso wenig
}
cout << '\n';
// Ausgabe: 1 2 -1 4 -2 1 2

