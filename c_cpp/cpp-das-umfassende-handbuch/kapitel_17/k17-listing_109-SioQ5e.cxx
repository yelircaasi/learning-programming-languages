#include <new> // nothrow
std::string *ps = new(std::nothrow) std::string{};
if(ps == nullptr) {
   std::cerr << "Die Speicheranforderung ging schief\n";
   return SOME_ERROR;
}

