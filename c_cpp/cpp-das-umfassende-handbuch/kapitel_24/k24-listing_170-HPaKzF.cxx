multimap int2int{ std::make_pair(3,4) };  // multimap<int,int>
using namespace std::literals; // für ""s
multimap<int,string> numlang{
    {7,"sieben"s}, {6,"six"s},
    {7,"siete"s}, {6,"sechs"s},
    {7,"seven"s}, {7,"yedi"s},
    {8,"eight"s} };
cout <<= numlang; // Ausgabe: 6:six 6:sechs 7:sieben 7:siete 7:seven 7:yedi 8:eight

