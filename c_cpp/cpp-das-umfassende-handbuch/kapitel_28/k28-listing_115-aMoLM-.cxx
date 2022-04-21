const regex muster{R"(^score)"
    R"(\s+)"
    R"((\d+))"          // Punkte
    R"(\s+)"
    R"(for)"
    R"(\s+)"
    R"((\d+))"          // Anzahl Nächte
    R"(\s+)"
    R"(night)"
    R"(s?)"             // optional: Plural
    R"(\s+)"
    R"(at)"
    R"(\s+)"
    R"((.*))"           // Hotelname
    R"()"};

