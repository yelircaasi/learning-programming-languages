void funktion(const MeinWert &paramRef) {
    MeinWert lokalWert{"lokal"};
}

int main() {
    MeinWert mwert1{"mwert1"};
    funktion( MeinWert{"temp"} );
    funktion( mwert1 );
    {
        MeinWert mwert2{"mwert2"};
    }
}

