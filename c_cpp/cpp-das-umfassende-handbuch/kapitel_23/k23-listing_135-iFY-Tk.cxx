template<>   // vollständige Spezialisierung
class MyPair<std::string, std::string> {
    std::vector<std::string> data_;
public:
    MyPair(const std::string& t, const std::string& u) : data_{t, u} { }
};
int main() {
    // nutzt die vollständige Spezialisierung:
    MyPair<std::string,std::string> strStr{"c","d"};
}

