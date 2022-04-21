namespace {
    const int MAX_A = 12;       // das Gleiche wie MAX_B, aber kein static nötig
}

static const int MAX_B = 10;    // im globalen Namensraum

struct Data {
    static const int SIZE = 14; // als Datenfeld in einer Klasse
}

void func() {
    static const int LIMIT =16; // als lokale Konstante
}

