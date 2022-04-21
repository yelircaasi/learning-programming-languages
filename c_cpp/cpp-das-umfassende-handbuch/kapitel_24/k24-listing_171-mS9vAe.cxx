using namespace std::literals; // für ""s

multimap<int,string> numlang{};
numlang.insert( std::make_pair(7, "seven"s) );
numlang.insert( std::pair<int,string>(7, "sieben"s) );
numlang.emplace( 7, "yedi"s );
cout <<= numlang; // Ausgabe: 7:seven 7:sieben 7:yedi

