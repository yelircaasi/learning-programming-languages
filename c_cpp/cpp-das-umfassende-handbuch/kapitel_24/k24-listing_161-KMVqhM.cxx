map<int,string> plz2ort;
plz2ort.insert(std::make_pair(53227, "Bonn"));
plz2ort.emplace(50667, "Koeln");
cout <<= plz2ort;                    // Ausgabe: 50667:Koeln 53227:Bonn
map<string,int> ort2plz;
ort2plz.emplace("Koeln", 50667);
ort2plz.emplace("Koeln", 51063);     // überschreibt nicht
cout <<= ort2plz;                    // Ausgabe: Koeln:50667

