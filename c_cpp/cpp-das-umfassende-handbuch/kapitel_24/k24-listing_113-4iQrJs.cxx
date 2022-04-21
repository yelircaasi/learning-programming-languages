vector<int> prims{ 2,3,5,7,11 };
vector gerade{ 2,4,6,8,10 };
vector<int> soNicht{ 'a', 4.3, 8L };     // "Narrowing" double nicht okay
vector<string> namen{ "sind", "nur" };   // konvertiert Argumente
vector schall{ "rauch", "qualm" };       // gefährlich: vector<const char[]>
vector nass{ "regen"s, "wasser"s };      // vector<string>
vector kalt{ "eis"sv, "pol"sv };         // vector<string_view>

