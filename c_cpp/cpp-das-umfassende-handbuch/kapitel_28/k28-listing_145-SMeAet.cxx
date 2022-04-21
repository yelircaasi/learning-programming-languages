#include <iostream>
#include <typeinfo>
#include <string>
#include <map>
#include <boost/core/typeinfo.hpp>

int main() {
  using std::string; using std::cout;
  std::map<int, string> namen;
  int ganz;
  double fliessend;

  // demangled_name
  using boost::core::demangled_name;
  cout<<demangled_name(BOOST_CORE_TYPEID(ganz))<<'\n';       // Ausgabe: int
  cout<<demangled_name(BOOST_CORE_TYPEID(fliessend))<<'\n';  // Ausgabe: double
  cout<<demangled_name(BOOST_CORE_TYPEID(string))<<'\n';     // Ausgabe: std::string
  cout<<demangled_name(BOOST_CORE_TYPEID(string{}.begin()))<<'\n';
  // Ausgabe: __gnu_cxx::__normal_iterator<char*, std::string>

  cout<<demangled_name(BOOST_CORE_TYPEID(namen))<<'\n';
  // Ausgabe: std::map<int, std::string, std::less<int>,
  //                                                         std::allocator<std::pair<int const, std::string> > >

  cout<<demangled_name(BOOST_CORE_TYPEID(666/0))<<'\n';      // Ausgabe: int
}

