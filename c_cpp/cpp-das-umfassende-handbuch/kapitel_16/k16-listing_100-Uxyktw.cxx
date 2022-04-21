struct MeinWert { /* irgendwas */ };
MeinWert globalWert{};                    // globale Klasseninstanz

void funktion(const MeinWert &paramRef) {
    if( /*...*/ ) funktion( /*x1?*/ );    // irgendeine Funktion aufrufen
    MeinWert lokalWert{};                 // lokale Klasseninstanz
}                                         // Ende der Funktion

int main() {
    MeinWert mwert1{};
    funktion( /*x2?*/ );
    funktion( MeinWert{} );               // temporärer Wert
    {
        MeinWert mwert2{};
        funktion( /*x3?*/ );
        MeinWert mwert3{};
    }                                     // Ende des inneren Blocks
    funktion( /*x4?*/ );
    MeinWert mwert4{};
    funktion( /*x5?*/ );
}                                         // Ende der main-Funktion

