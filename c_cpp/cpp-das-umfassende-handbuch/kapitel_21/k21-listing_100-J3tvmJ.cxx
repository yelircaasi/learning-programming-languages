// Dateiname: meine-makros.hpp
#ifndef MEINE_MAKROS_HPP  // Include Guard
#define MEINE_MAKROS_HPP

#include <iostream> // cout, cerr
#include <vector>
#ifdef AUSGABE_AUF_STANDARD
#  define OUT std::cout
#else
#  define OUT std::cerr
#endif
#define MESSAGE(text) { (OUT) << text << "\n"; }
using container_type = std::vector<int>;
static constexpr unsigned SIZE = 10;

#endif

