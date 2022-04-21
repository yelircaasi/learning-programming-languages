const size_t verdoppleWennZuKlein2(size_t wert) {
    return wert < 100 ? wert*2 : wert;
}
std::array<int, verdoppleWennZuKlein2(50)> arr {};

