vector vokale { 'A', 'e', 'i', 'o', 'u' };
const vector gerade { '0', '2', '4', '6', '8' };

auto it1 = vokale.begin();                  // vector<char>::iterator
*it1='a'; // liefert 'char&' zurück

auto it2 = gerade.begin();                  // vector<char>::const_iterator
auto it3 = vokale.cbegin();                 // erzwingt const_iterator
*i2='9'; *i3='x';                           // 'const char&' ist nicht veränderbar

for(auto it=vokale.cbegin()+1; it!=vokale.cend(); ++it)
    { cout << *it; } cout << '\n';          // Ausgabe: eiou
for(auto it=vokale.crbegin()+1; it!=vokale.crend(); ++it) // ++ trotz reverse!
    { cout << *it; } cout << '\n';          // Ausgabe: oiea

