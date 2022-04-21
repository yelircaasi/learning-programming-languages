#include <random>
#include <chrono>  // system_clock
#include <iomanip> // setw
#include <iostream>

using namespace std;
using namespace chrono;
const size_t LOOPS = 10*1000*1000;

template<typename ENGINE>
void messen(const string &title, ENGINE &engine) {
  const auto start = steady_clock::now();

  /* hart arbeiten */
  unsigned long long checksum = 0;
  size_t loops = LOOPS;
  while(loops-- > 0)
    checksum += engine();

  const auto now = steady_clock::now();
  nanoseconds dur_ns = now - start;
  cout << "  " << title << ": "
       << setw(5) << (dur_ns.count() / LOOPS) << " ns/loop  "
       << setw(12) << dur_ns.count() << " ns  "
       << endl;
}

int main() {
  { default_random_engine e{}; messen("      default", e ); }
  { random_device e{};         messen("       device", e ); }
  { minstd_rand0 e{};          messen(" minstd_rand0", e ); }
  { minstd_rand e{};           messen(" minstd_rand ", e ); }
  { mt19937 e{};               messen("   mt19937   ", e ); }
  { mt19937_64 e{};            messen("   mt19937_64", e ); }
  { ranlux24_base e{};         messen("ranlux24_base", e ); }
  { ranlux48_base e{};         messen("ranlux48_base", e ); }
  { ranlux24 e{};              messen("ranlux24     ", e ); }
  { ranlux48 e{};              messen("ranlux48     ", e ); }
  { knuth_b e{};               messen("      knuth_b", e ); }
  {
    using wide_t = unsigned long long ;
    independent_bits_engine<ranlux48, sizeof(wide_t)*8, wide_t> e{};
    messen("indep<ranlux>", e );
  }
  {
    using wide_t = unsigned long long;
    independent_bits_engine<
          default_random_engine,
          sizeof(wide_t)*8, wide_t>
      e {};
    messen("indep<default>", e );
  }
}

