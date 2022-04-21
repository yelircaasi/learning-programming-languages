#include <iostream>                // cout
#include <vector>
using std::vector;

vector<int> createData(size_t sz) {
    return vector<int>(sz);        // sz x null
}
void fibonacci(vector<int> &data) {
    for(auto it = begin(data)+2; it != end(data); ++it) { // iterator it
        *it = *(it-1) + *(it-2);
    }
}

std::ostream& print(std::ostream &os, const vector<int> &data) {
    for(auto it=begin(data); it != end(data); ++it)       // const_iterator it
        std::cout << *it << " ";
    return os;
}

int main() {
    vector<int> data = createData(10);
    data[0] = 1;
    data[1] = 1;
    fibonacci(data);
    print(std::cout, data) << "\n";
}

