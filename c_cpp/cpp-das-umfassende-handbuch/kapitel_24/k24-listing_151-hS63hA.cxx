set data{ 10, 20, 30, 40, 50, 60, 70 };
set<int> ziel;
auto hinweis = ziel.begin();
for(auto &e : data) {
    hinweis =                    // Einfügeposition in nächster Runde nutzen
        ziel.insert(hinweis, e); // Hinweis hilft, weil data sortiert ist
}

