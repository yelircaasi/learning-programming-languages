#include "impl_multimap.hpp" // Header zu dieser Datei
#include <map>
#include <string>
#include <string_view>

namespace qw::impl_multimap {

using std::vector; using std::multimap; using std::map; using std::string;
using std::string_view; using namespace std::literals::string_literals;

void index_impl::add(string_view normalized, string_view original) {
    /* TODO: Vorhandensein in 'entries' prüfen */
    const auto pos = entries.size(); // Index des neuen Eintrags
    entries.push_back(string(original));
    auto qgrams = qgramify(normalized);
    for(const auto& qgram : qgrams) {
        qindex.insert( make_pair(qgram, pos) );
    }
}
string index_impl::getBestMatch(string_view normalized) const {
    auto qgrams = qgramify(normalized);
    /* hits speichert, welche Wörter wie oft getroffen wurden */
    map<size_t, size_t> hits; /* 'entries-index' zu 'hit-count' */
    size_t maxhits = 0; /* immer: max(hits.second) */
    for(const auto& qgram : qgrams) {
        auto range = qindex.equal_range(qgram);
        for(auto it=range.first; it!=range.second; ++it) {
            hits[it->second] += 1; /* hit-count des Eintrags */
            if(hits[it->second] > maxhits) { /* max-Suche einfacher */
                maxhits = hits[it->second];
            }
        }
    }
    /* Suche ersten Eintrag mit maxhits. Bessere Impl. mit PrioQueue möglich */
    for(auto const &hit : hits) {
        if(hit.second == maxhits) {
            return entries[hit.first];
        }
    }
    /* nur erreicht, wenn entries leer ist */
    return ""s;
}
const string index_impl::PREFIX = string(Q-1, '^');
const string index_impl::SUFFIX = string(Q-1, '$');

vector<string> index_impl::qgramify(string_view normalized) const {
    auto word = PREFIX + string(normalized)+SUFFIX; /* Trick für bessere QGramme */
    vector<string> result {};
    auto left = word.cbegin();
    auto right = std::next(word.cbegin(), Q); /* okay wg: |"^^"|+|"$$"| => 3 */
    for( ; right <= word.end(); ++left, ++right) {
        result.emplace_back(left, right);
    }
    return result;
}

} // namespace qw::impl_multimap

