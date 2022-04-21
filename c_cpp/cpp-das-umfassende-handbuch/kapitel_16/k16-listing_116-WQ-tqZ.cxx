#include <iostream>  // istream, ostream, cout
class Num {
  int val_ = 0;
public:
  int& operator*();  // Dereferenzieren: Zugriff auf den Wert direkt erhalten
  const int& operator*() const; // Dereferenzieren: Lesezugriff auf den Wert
  Num() {}
  explicit Num(int value) : val_{value} {}

  // einstellige Operatoren
  Num& operator++(); // Pre-Inkrement
  Num& operator--(); // Pre-Dekrement
  Num operator+();   // Positiv
  Num operator-();   // Negieren
  Num operator~();   // bitweises Invertieren

  // zweistellige Operatoren
  // - zusammengesetzte Zuweisungen, arithmetisch
  Num& operator+=(const Num& re) { val_ += *re; return *this; }
  Num& operator-=(const Num& re) { val_ -= *re; return *this; }
  Num& operator*=(const Num& re) { val_ *= *re; return *this; }
  Num& operator/=(const Num& re) { val_ /= *re; return *this; }
  Num& operator%=(const Num& re) { val_ %= *re; return *this; }
  // - zusammengesetzte Zuweisungen, bitweise
  Num& operator|=(const Num& re) { val_ |= *re; return *this; }
  Num& operator&=(const Num& re) { val_ &= *re; return *this; }
  Num& operator^=(const Num& re) { val_ ^= *re; return *this; }
  Num& operator<<=(int n) { val_ <<= n; return *this; }
  Num& operator>>=(int n) { val_ >>= n; return *this; }
  // - Variation zusammengesetzter Zuweisungen, für einfachere Bedienung
  Num& operator+=(int re) { val_ += re; return *this; }
  Num& operator-=(int re) { val_ -= re; return *this; }
  // zweistellige Operatoren, mit Call-by-Value für den ersten Parameter
  //   und die die zusammengesetzte Zuweisung zu Hilfe nehmen
  // - Arithmetik
  friend Num operator+(Num li, const Num& re) { return li += re; }
  friend Num operator-(Num li, const Num& re) { return li -= re; }
  friend Num operator*(Num li, const Num& re) { return li *= re; }
  friend Num operator/(Num li, const Num& re) { return li /= re; }
  friend Num operator%(Num li, const Num& re) { return li %= re; }
  // - bitweise
  friend Num operator|(Num li, const Num& re) { return li |= re; }
  friend Num operator&(Num li, const Num& re) { return li &= re; }
  friend Num operator^(Num li, const Num& re) { return li ^= re; }
  // - Vergleiche
  // - ... fundamental für Standardcontainer und -algorithmen
  friend bool operator<(const Num& li, const Num& re) { return *li < *re; }
  friend bool operator==(const Num& li, const Num& re) { return *li == *re; }
  // - ... erweiterte Vergleiche
  friend bool operator>(const Num& li, const Num& re) { return *li > *re; }
  friend bool operator<=(const Num& li, const Num& re) { return *li <= *re; }
  friend bool operator>=(const Num& li, const Num& re) { return *li >= *re; }
  friend bool operator!=(const Num& li, const Num& re) { return *li != *re; }
  // - Ein- und Ausgabe
  friend std::ostream& operator<<(std::ostream& os, const Num& arg);
  friend std::istream& operator>>(std::istream& is,  Num& arg);
};

// einstellige Operatoren
Num& Num::operator++() { ++val_; return *this; }
Num& Num::operator--() { --val_; return *this; }
Num Num::operator+() { return Num{val_}; }
Num Num::operator-() { return Num{-val_}; }
Num Num::operator~() { return Num{~val_}; }
int& Num::operator*() { return val_; }
const int& Num::operator*() const { return val_; }

// Ein- und Ausgabe
std::ostream& operator<<(std::ostream&os, const Num& arg) { return os<<*arg; }
std::istream& operator>>(std::istream&is, Num& arg) { return is>>*arg; }

