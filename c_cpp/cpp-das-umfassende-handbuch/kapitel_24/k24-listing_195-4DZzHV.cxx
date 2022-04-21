#include <iostream>
#include <iomanip> // setw
#include <valarray>

using namespace std;

/* Matrix drucken */
template<class T>
void printMatrix(ostream&os, const valarray<T>& a, size_t n) {
    for(size_t i = 0; i < (n*n); ++i) {
        os << setw(3) << a[i];        // Wert drucken
        os << ((i+1)%n ? ' ' : '\n'); // nächste Zeile?
    }
}

/* Matrix-Kreuzprodukt */
template<class T>
valarray<T> matmult(
        const valarray<T>& a, size_t arows, size_t acols,
        const valarray<T>& b, size_t brows, size_t bcols)
{
    /* Bedingung: acols==brows */
    valarray<T> result(arows * bcols);
    for(size_t i = 0; i < arows; ++i) {
      for(size_t j = 0; j < bcols; ++j) {
        auto row = a[slice(acols*i, acols, 1)]; // Zeile
        auto col = b[slice(j, brows, bcols)];   // Spalte
        result[i*bcols+j] = (row*col).sum();    // Kreuzprodukt Zeile a[i] und Spalte b[j]
      }
    }
    return result;
}
int main() {
    constexpr int n = 3;
    valarray ma{1,0,-1,  2,2,-3,  3,4,0};         // 3 x 3-Matrix
    valarray mb{3,4,-1,  1,-3,0,  -1,1,2};        // 3 x 3-Matrix
    printMatrix(cout, ma, n);

    cout << "  -mal-\n ";
    printMatrix(cout, mb, n);

    cout << "  -ergibt-:\n ";
    valarray<int> mc = matmult(ma, n,n, mb, n,n);
    printMatrix(cout, mc, n);
}

