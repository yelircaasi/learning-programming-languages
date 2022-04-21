map<char,int> data { { 'a',1}, {'b',2}, {'c',3} };
for(auto it=data.rbegin(); it!=data.rend(); ++it) {  // rückwärts
    cout << it->first << ':' << it->second << ' ';   // Iterator mit -> dereferenzieren
}
cout << '\n'; // Ausgabe: c:3 b:2 a:1
for(auto &e : data) {                          // vorwärts, nimmt begin() und end()
    cout << e.first << ':' << e.second << ' '; // Paar mit . zugreifen
}
cout << '\n'; // Ausgabe: a:1 b:2 c:3

