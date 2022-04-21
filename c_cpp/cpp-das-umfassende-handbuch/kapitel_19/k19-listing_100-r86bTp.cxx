class Auto { };
  class VwBulli : public Auto { };
  class Ente : public Auto { };
void lassFahren(Auto wagen) { }   // Wertparameter
void lassBremsen(Auto &wagen) { } // Referenzparameter
void lassHupen(Auto *wagen) { }   // Übergabe als Zeiger
int main() {
    VwBulli bulli{  };            // automatische Variable
    Auto *ente = new Ente{  };    // dynamisch verwaltet
    lassFahren(bulli);            // wird zum Auto kopiert
    lassFahren(*ente);            // wird zum Auto kopiert
    lassBremsen(bulli);           // bleibt VwBulli
    lassBremsen(*ente);           // bleibt Ente
    lassHupen(&bulli);            // bleibt VwBulli
    lassHupen(ente);              // bleibt Ente
}

