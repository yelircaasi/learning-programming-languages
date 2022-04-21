#include "qwort/qwort.hpp" // selbst

#include <map>
#include <algorithm> // transform
#include <cctype> // toupper

using std::map;
using std::string;

namespace qw {

    int version() {
        return 1;
    }

    namespace impl_map {

        class index_impl {
            map<string,string> data;

        public:

            void add(const string &normalized, const string& original) {
                data[normalized] = original;
            }

            size_t size() const {
                return data.size();
            }

            string getBestMatch(const string& normalized) const {
                const auto where = data.find(normalized);
                return where != data.end() ? where->second : "";
            }
        };

    } // namespace impl_map


    // === Index Hauptklasse ===

    index::index()
        : pimpl{ new index_impl{} }
        { }

    // Einen nicht-Default Destruktor im Header erlaubt die Verwendung eines
    //   nicht-kompletten Typen mit unique_ptr, und somit den schönen Einsatz
    //   des Pimpl-Patterns. http://stackoverflow.com/a/9064437/472245
    index::~index() {
    }

    void index::add(const string &arg) {
        pimpl->add(normalize(arg), arg);
    }

    string index::normalize(string str) const {
        using namespace std; // begin, end
        transform(begin(str), end(str), begin(str), [](char c) {
                return ::isalpha(c) ? ::toupper(c) : '#';
            });
        return str;
    }

    size_t index::size() const {
        return pimpl->size();
    }

    string index::getBestMatch(const string& query) const {
        return pimpl->getBestMatch(normalize(query));
    }


} // namespace qw
