enum class Wochentag {
    MO=1, DI, MI, DO, FR, SA, SO         // DI wird 2, MI wird 3 etc.
};

enum class Level {
   TRACE=1, DEBUG, INFO=10, ERROR, FATAL // auch mit Lücken möglich
};

void log(Level level) {
   int intLevel = (int)level;            // explizit in einen int umwandeln
   if(intLevel > 10) { /* ... */ }
}

