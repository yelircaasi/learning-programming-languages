#include <set>
#include <vector>
#include <iostream>
using std::cout; using std::ostream; using std::set; using std::vector;

template<typename Container>
void insFive(Container& cont, int a, int b, int c, int d, int e) {
    auto it = cont.end();
    for(int x : { a, b, c, d, e }) {
        it = cont.insert(it, x); // geht mit vector, set etc.
    }
}

int main() {
    vector<int> dataVec{ };
    insFive(dataVec, 9, 2, 2, 0, 4 );
    for(auto e : dataVec) cout <<e<<' ';
    cout << '\n'; // Ausgabe: 4 0 2 2 9
    set<int> dataSet{ };
    insFive(dataSet, 9, 4, 2, 2, 0);
    for(auto e : dataSet) cout <<e<<' ';
    cout << '\n'; // Ausgabe: 0 2 4 9
}

