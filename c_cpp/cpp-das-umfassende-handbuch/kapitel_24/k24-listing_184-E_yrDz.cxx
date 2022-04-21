 struct EqEintrag {
     bool operator()(const Eintrag&a, const Eintrag&b) const {
         return a.stadt_==b.stadt_;
     }
 };
 struct HashEintrag {
     std::hash<string> sHash;
     std::hash<int> iHash;
     size_t operator()(const Eintrag& a) const {
         return sHash(a.stadt_) ^ iHash(a.plz_);
     }
 };

