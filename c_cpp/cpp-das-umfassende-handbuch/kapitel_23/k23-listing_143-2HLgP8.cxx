namespace lits {

  // Template-Hilfsfunktion für _ein_ Argument
  template<char C> int bin() {  // allgemeiner Fall
    if constexpr (C=='0') return 0;
    else if constexpr (C=='1') return 1;
  }
  // Template-Hilfsfunktion ab _zwei_ Argumente
  // ...

}

