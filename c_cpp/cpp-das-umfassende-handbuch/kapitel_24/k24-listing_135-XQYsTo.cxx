void alle(const array<int,4>& a, const array<int,4>& b) {
     cout << "{"<<a<<"} verglichen mit {"<<b<<"} ist "
       << (a < b ? "<, " : "")
       << (a <= b ? "<=, " : "")
       << (a > b ? ">, " : "")
       << (a >= b ? ">=, " : "")
       << (a == b ? "==, " : "")
       << (a != b ? "!=, " : "")
       << '\n';
}

int main() {
    array a{10,10,10,10};
    array b{20, 5, 5, 5};
    array c{10,10,5,21};
    array d{10,10,10,10};
    cout << (a < b ? "kleiner\n" : "nicht kleiner\n"); // "kleiner", weil 10 < 20
    cout << (a < c ? "kleiner\n" : "nicht kleiner\n"); // "nicht ...", weil nicht 10 < 5
    cout << (a == d? "gleich\n" : "nicht gleich\n");   // "gleich", weil alles 10
    for(auto &x : {a,b,c}) {
        for(auto &y : {a,b,c}) {
            alle(x,y);
        }
    }
}

