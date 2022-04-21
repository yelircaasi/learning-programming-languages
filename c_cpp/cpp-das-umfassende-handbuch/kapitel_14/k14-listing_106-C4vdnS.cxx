#ifndef QWORT_H   // Header-Guard
#define QWORT_H
#include <string>
#include <string_view>
#include <memory> // unique_ptr

namespace qw {    // Namensraum der Bibliothek

    int version();

    namespace impl_multimap {
        class index_impl;
    }

    class index {
        using index_impl = impl_multimap::index_impl;
    public:
        index();
        ~index() noexcept; // wird für pimpl benötigt
        index(const index&) = delete;
        index(index&&) noexcept;
        index& operator=(const index&) = delete;
        index& operator=(index&&) = delete;
    public:
        void add(std::string_view arg);
        size_t size() const;
        std::string getBestMatch(std::string_view query) const;

    public:          // public für Tests
        std::string normalize(std::string arg) const;
    private:
        std::unique_ptr<index_impl> pimpl;
    };

} // namespace qw
#endif // Header-Guard

