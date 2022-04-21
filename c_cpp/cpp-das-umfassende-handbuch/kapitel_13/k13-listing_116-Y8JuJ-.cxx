constexpr size_t verdoppleWennZuKlein1(size_t wert) {
   return wert < 100 ? wert*2 : wert; // liefert das Doppelte zurück, wenn kleiner 100
}
std::array<int, verdoppleWennZuKlein1(50)> arr {};

