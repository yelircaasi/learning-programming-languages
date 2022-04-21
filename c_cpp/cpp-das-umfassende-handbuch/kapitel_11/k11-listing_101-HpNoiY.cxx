#include "qwort/qwort.hpp" // selbst
#include <map>
#include <algorithm> // transform
#include <cctype> // toupper
#include "impl_multimap.hpp"
using std::map; using std::string;

namespace qw {
    int version() {
        return 1;
    }
    // Verwaltung
    index::index()
        : pimpl{ new index_impl{} }
        { }
    index::~index() noexcept = default;
    index::index(index&&) noexcept = default;
    // Schnittstelle
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

