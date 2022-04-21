// befüllen mit 100 Werten
unordered_set<int> d{};
d.rehash(10); // versuche, 10 Eimer zu haben
d.max_load_factor(100.0); // 100 Elemente pro Eimer sind okay
cout << "Eimer Anzahl: " << d.bucket_count() << '\n';
for(int x=0; x<100; ++x) {
    d.insert(x);
}
// ausgeben
for(int b = d.bucket_count()-1; b>=0; --b) {
    cout << "Eimer "<<b<<":";
    for(auto it=d.begin(b); it!=d.end(b); ++it)
        cout << *it << ' ';
    cout << '\n';
}

