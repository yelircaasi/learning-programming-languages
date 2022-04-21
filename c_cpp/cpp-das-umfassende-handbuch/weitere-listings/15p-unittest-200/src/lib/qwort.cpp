#include "qwort/qwort.hpp" // selbst

#include <map>
#include <algorithm> // transform
#include <cctype> // toupper

#include "impl_multimap.hpp"

using std::map;
using std::string;

namespace qw {

    int version() {
        return 1;
    }

    // === Index Hauptklasse ===

    index::index()
        : pimpl{ new index_impl{} }
        { }

    // Einen nicht-Default Destruktor im Header erlaubt die Verwendung eines
    //   nicht-kompletten Typen mit unique_ptr, und somit den schönen Einsatz
    //   des Pimpl-Patterns. http://stackoverflow.com/a/9064437/472245
    //   Leider geht damit die Compiler-generierte default-Implementierung
    //   nicht. Aber wenn wir dies in der Cpp-Datei _nach_ dem Include
    //   der Implementierung machen, dann klappts.
    index::~index() noexcept = default;
    index::index(index&&) noexcept =default;

    void index::add(const string &arg) {
        pimpl->add(normalize(arg), arg);
    }

    size_t index::size() const {
        return pimpl->size();
    }

    string index::getBestMatch(const string& query) const {
        return pimpl->getBestMatch(normalize(query));
    }

    string index::normalize(string str) const {
        using namespace std; // begin, end
        transform(begin(str), end(str), begin(str), [](char c) {
                return ::isalpha(c) ? ::toupper(c) : '#';
            });
        return str;
    }


} // namespace qw
