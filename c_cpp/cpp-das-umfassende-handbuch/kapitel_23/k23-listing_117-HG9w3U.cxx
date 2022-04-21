set<Zwerg,NachJahr> zwerge2{begin(zwerge), end(zwerge)};
for(const auto& z : zwerge2) // anders sortierte Ausgabe
    cout << z.jahr_ << " ";

