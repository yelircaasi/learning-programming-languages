#include <vector>
// ...
set data{1,2,3,4,5};
std::vector quelle{10, 20, 30, 40, 50};

// Es gibt kein set::assign:
data.assign(quelle.begin(), quelle.end());

// Simulieren Sie es also mittels eines temporären set:
set temp(quelle.begin(), quelle.end());      // aus Quelle kopieren ...
data.swap(temp);                             // ... Inhalte effizient vertauschen
cout <<= data; // Ausgabe: 10 20 30 40 50

// ... oder per vorherigem clear und darauffolgendem insert:
data.clear();                                // leeren ...
data.insert(quelle.begin(), quelle.end());   // ... und einfügen
cout <<= data; // Ausgabe: 10 20 30 40 50

