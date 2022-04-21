#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>

using std::string; using std::unordered_set; using std::cout;
struct Word {
    string word_;
    size_t row_;
    Word(const string &word, size_t row)
        : word_{word}, row_{row} {}
    friend bool operator==(const Word& a, const Word &b)
        { return a.word_ == b.word_; } // ignoriert row
 };
 namespace std {
 template<> struct hash<Word> { // ignoriert row
        std::hash<string> stringHash;
        std::size_t operator()(const Word &w) const {
            return stringHash(w.word_);
        }
 }; }
 struct ExactWordHash { // bezieht row mit ein
     std::hash<string> sHash;
     std::hash<size_t> iHash;
     bool operator()(const Word& a) const {
         return sHash(a.word_) ^ iHash(a.row_);
     }
 };
 struct ExactWordEqual { // bezieht row mit ein
     bool operator()(const Word& a, const Word &b) const {
         return std::tie(a.word_, a.row_) == std::tie(b.word_, b.row_);
     }
 };
 int main() {
     std::vector input {
       Word{"eine",0}, Word{"Rose",0},
       Word{"ist",1}, Word{"eine",1}, Word{"Rose",1},
       Word{"ist",2}, Word{"eine",2}, Word{"Rose",2},  };
     // Überladungen nutzen
     unordered_set<Word> words( input.begin(), input.end() );
     cout << words.size() << '\n'; // Ausgabe: 3
     // Eigene Funktoren nutzen
     unordered_set<Word,ExactWordHash,ExactWordEqual> poem(
          input.begin(), input.end() );
     cout << poem.size() << '\n';  // Ausgabe: 8
     // Hash als Lambda
     auto h = [](const auto &a) { return std::hash<string>{}(a.word_); };
     unordered_set<Word,decltype(h)> rose(input.begin(), input.end(), 10, h);
     cout << rose.size() << '\n';  // Ausgabe: 3
 }

