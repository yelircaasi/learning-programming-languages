#include <functional> // function
int berechne(int a, int b, std::function<int(int,int)> binop) {
    return binop(a,b);
}

