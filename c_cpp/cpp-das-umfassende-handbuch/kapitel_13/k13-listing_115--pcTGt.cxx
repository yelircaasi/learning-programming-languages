struct Data {
    static constexpr size_t SPAET; // klappt nicht ohne direkte Initialisierung
    static constexpr size_t FRUEH = 10;
};
constexpr size_t Data::SPAET = 10; // bei constexpr geht Definition nicht wie bei const

