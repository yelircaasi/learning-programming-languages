#include <array>
#include <numeric> // accumulate
#include <iostream>

template<size_t SZ>
int sumSz(const std::array<int,SZ>& data) {
    int result = 0;
    for(auto i=0u; i<SZ; ++i)
        result += data[i];
    return result;
}
template<typename Elem, size_t SZ>
Elem sumElem(const std::array<Elem,SZ>& data) {
    Elem result {0};
    for(auto i=0u; i<SZ; ++i)
        result += data[i];
    return result;
}
template<typename It>
int sumIt(It begin, It end) {
    return std::accumulate(begin, end, 0);
}
int main() {
   using namespace std;
   array<int,4> a4 { 1, 2, 5, 8 };
   cout << sumSz<4>(a4) << '\n';                // 16
   array<int,5> a5 { 1, -5, 3, 7, 2 };
   cout << sumElem(a5) << '\n';                 // 8
   array<int,6> a6 { 1,2,3, 4,5,6 };
   cout << sumIt(a6.begin(), a6.end()) << '\n'; // 21
   array a7 { 1,2,3, 4,5,6, 7 };                // array<int,7>
   cout << sumIt(a7.begin(), a7.end()) << '\n'; // 28
}

