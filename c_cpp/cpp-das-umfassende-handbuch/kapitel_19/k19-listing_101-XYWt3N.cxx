struct Buch {
   auto getTitel() { return Titel{"Das C++ Handbuch"s}; }
   auto getAutor() { return Autor{"Torsten T. Will"s}; }
   auto umblaettern() { return /* Referenz zur nächsten Seite */ 42; }
   auto getSeite() { return "aktueller Seiteninhalt"; }
   auto getStandort() { return /* Regalnummer/Buchnummer */ 73; }
};

