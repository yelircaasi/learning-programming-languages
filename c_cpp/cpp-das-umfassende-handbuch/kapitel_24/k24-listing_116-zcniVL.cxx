vector<int> von{ 2,3,4 };
vector<int> nach{};
nach = von;                         // Zuweisung mit operator=, nun beide gleich

vector<int> abfluss{};
abfluss = std::move(von);           // Verschieben, nun ist 'von' leer
vector<int> v;
v.assign(4, 100);                   // v ist nun {100, 100, 100, 100}
v.assign(nach.begin(), nach.end()); // v ist nun {2,3,4}
int z[] = { 10, 20, 30, 40 };
v.assign(z+1, z+4);                 // v ist nun {20, 30, 40}

