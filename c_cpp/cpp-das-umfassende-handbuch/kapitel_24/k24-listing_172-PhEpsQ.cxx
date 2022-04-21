multimap<char,int> vals{ {'c',1}, {'c',8}, {'g',1},
    {'c',1}, {'a',7}, {'a',1}, {'c',2}, };
cout <<= vals;            // Ausgabe: a:7 a:1 c:1 c:8 c:1 c:2 g:1
vals.erase( @'@c@'@ );        // löscht alle 'c's
cout <<= vals;            // Ausgabe: a:7 a:1 g:1
vals.erase(vals.begin()); // löscht nur eines der 'a's
cout <<= vals;            // Ausgabe: a:1 g:1

