#include <vector>
#include <set>
#include <iostream> // cout
using std::vector; using std::set; using std::cout;
using vector_t = vector<unsigned long long>; // Ihr eigener Typalias
int main() {
    vector_t huge{ 12ULL, 10000000000ULL, 9ULL, 0ULL,  };
    auto sz = huge.size();
    auto uiuiui = huge[1];
    for(auto it = huge.begin(); it != huge.end(); ++it)
        *it *= 2; // verdoppeln
    /* sortieren per set */
    set sortiert(huge.begin(), huge.end());  // set<vector_t::value_type>
    for(auto val : sortiert)
        cout << val << " ";
    cout << "\n";
}

