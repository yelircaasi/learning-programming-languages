using std::pair; using std::make_pair;
namespace literal_p { // benutzerdefinierte Literale besser immer in Namespace packen
constexpr pair<char,char> operator "" _p(const char* s, size_t len) {
    return len>=2 ?make_pair(s[0], s[1]) : make_pair( '-', '-' );
} }
struct Q {
    char a_; int n_;
    Q(char a, int n) : a_{a}, n_{n} {}
    operator pair<const char,int>() { return make_pair(a_, n_); }
};
// ...
// explizite Paare:
map<int,int> nums { pair<int,int>(3,4), make_pair(7,8), make_pair(11,23) };
map nums2 { pair<int,int>(6,1), make_pair(5,2) };  // map<int,int> dank pair
map<int,char> numch{{1,@'@a@'@},{2,@'@b@'@},{3,@'@c@'@}};   // auch pair als Initialisierungslisten
using namespace literal_p;
map<char,char> pmap { "ab"_p, "cd"_p, "ef"_p }; // Umweg über eigenes Literal
cout <<= pmap;                                  // Ausgabe: a:b c:d e:f
map<char,int> qmap{Q(@'@a@'@,1),Q(@'@b@'@,2),Q(@'@c@'@,3)}; // implizite Umwandlungen sind okay
cout <<= qmap;                                  // Ausgabe: a:1 b:2 c:3

