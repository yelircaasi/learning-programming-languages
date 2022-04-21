#include <deque>
// ...
std::deque in{1,2,33,34,35,99};
vector dreissig(in.begin()+2, in.begin()+5);
for(auto &e : dreissig) {
    cout << e << ' ';
}
cout << '\n';

