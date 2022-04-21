#ifndef QWORT_H // Header-Guard
#define QWORT_H

#include <string>
#include <memory> // unique_ptr

namespace qw { // Namensraum der Bibliothek
    int version();
    namespace impl_multimap {
        class index_impl;
    }
    class index {
        using index_impl = impl_multimap::index_impl;
    public:
        index();
        ~index() noexcept; // wird für pimpl benötigt
        index(const index&) = default;
        index(index&&) noexcept;
        index& operator=(const index&) = default;
        index& operator=(index&&) = default;
    public:
        void add(const std::string &arg);
        size_t size() const;
        std::string getBestMatch(const std::string& query) const;
    public:          // public für Tests
        std::string normalize(std::string arg) const;
    private:
        const std::unique_ptr<index_impl> pimpl;
    };
} // namespace qw
#endif // Header-Guard

