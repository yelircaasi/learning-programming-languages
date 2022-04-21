#include <vector>
#include <iostream> // cout
using std::vector; using std::cout;
int main() {
    vector data{ 12, 100, -1, 0,  };    // vector<int>
    for(auto& val : data)
        val *= 2; // verdoppeln
    for(const auto val : data)
        cout << val << " ";
    cout << "\n";
}

