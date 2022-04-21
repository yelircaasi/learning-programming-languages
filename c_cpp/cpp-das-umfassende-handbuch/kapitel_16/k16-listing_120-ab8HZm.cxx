#include <string>
using std::string;

enum class Ampelfarbe {
    ROT, GELB, ROTGELB, GRUEN
};
struct Ampel {
    Ampelfarbe farbe_;
    Ampel(Ampelfarbe farbe, string name) : farbe_{farbe} {}
};

Ampel erzeugeAmpel(Ampelfarbe farbe, string ampelName) {
    return Ampel{farbe, ampelName};
}

int main() {
    Ampel ampel = erzeugeAmpel(Ampelfarbe::ROT, "AX-001");
}

