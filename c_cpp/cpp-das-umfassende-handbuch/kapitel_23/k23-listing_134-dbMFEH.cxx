#include <string>
#include <tuple>

template <typename T, typename U=T> // allgemeiner Fall
class MyPair {
    T data01_;
    U data02_;
public:
    MyPair(const T& t, const U& u) : data01_{t}, data02_{u} {}
};

template <typename T>           // teilweise Spezialisierung, T bleibt formal
class MyPair<T, std::string> {  // U ist auf string spezialisiert
    std::tuple<T,std::string> data_;
public:
    MyPair(const T& t, const std::string& str) : data_{t, str} { }
};

template <typename U>           // teilweise Spezialisierung, U bleibt formal
class MyPair<std::string, U> {  // T ist auf string spezialisiert
    std::tuple<std::string, U> data_;
public:
    MyPair(const std::string& str, const U& u) : data_{str, u} { }
};

int main() {
  MyPair<int,std::string> intString{1, "a"};       // nutzt partielle Spezialisierung
  MyPair<std::string,int> stringInt{"b", 2};       // nutzt partielle Spezialisierung
  MyPair<int,int> intInt{3,4};                     // nutzt allgemeinen Fall
  MyPair intInt2{3,4};                             // auch MyPair<int,int>
  MyPair<std::string,std::string> strStr{"c","d"}; // mehrdeutig
}

