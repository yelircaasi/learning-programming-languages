const string scoreKeyword = R"(^score\s+)";
const string numberOfPoints = R"((\d+))";
const string forKeyword = R"(\s+for\s+)";
const string numberOfNights = R"((\d+))";
const string nightsAtKeyword = R"(\s+nights?\s+at\s+)";
const string hotelName = R"((.*))";

const regex muster{ scoreKeyword + numberOfPoints +
    forKeyword + numberOfNights + nightsAtKeyword + hotelName };
}

