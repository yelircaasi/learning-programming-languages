vector<char> leseDatei(const string& fName) {
    std::ifstream file{ fName, std::ifstream::binary };
    if(!file) throw std::runtime_error("Fehler beim Oeffnen der Eingabe");
    file.seekg(0, file.end);          // ans Dateiende springen
    const auto laenge = file.tellg(); // aktuelle Position ist Dateigröße

    if(laenge > 1024*1024*1024)
        throw std::runtime_error("Nicht mehr als 1 GB bitte");
    file.seekg(0, file.beg);          // zurück an den Anfang
    vector<char> data(laenge);        // Platz schaffen
    file.read(data.data(), laenge);   // in einem Rutsch lesen
    return data;                      // wird nicht kopiert (Stichwort: RVO)
}
void packe(const string& fNameIn, const string& fNameOut) {
    auto data = leseDatei(fNameIn);   // lese Eingabe
    GzWriteStream gz{fNameOut};       // initialisiere Ausgabe
    gz << data;
}

