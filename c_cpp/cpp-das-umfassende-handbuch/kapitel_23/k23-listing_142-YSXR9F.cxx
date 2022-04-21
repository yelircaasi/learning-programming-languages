namespace lits {
  // Template-Hilfsfunktion für _ein_ Argument
  template<char C> int bin();  // allgemeiner Fall
  template<>       int bin<'1'>() { return 1; } // Spez.
  template<>       int bin<'0'>() { return 0; } // Spez.
  // Template-Hilfsfunktion ab _zwei_ Argumente
  template<char C, char D, char... ES>
  int bin() {
    return bin<C>() << (sizeof...(ES)+1) | bin<D,ES...>(); // Bit-Shift und Bit-Oder
  }
  // eigentlicher operator""
  template<char...CS> int operator"" _bin()
    { return bin<CS...>(); };
}
int main() {
  using namespace lits;
  int eins = 1_bin;
  int acht = 1000_bin;
  int neun = 1001_bin;
  int zehn = 1010_bin;
  int elf  = 1011_bin;
  int hundertachtundzwanzig = 10000000_bin;
}

