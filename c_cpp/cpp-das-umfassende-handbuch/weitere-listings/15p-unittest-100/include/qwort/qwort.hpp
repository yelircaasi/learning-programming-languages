#include <string>
#include <memory> // unique_ptr

namespace qw {

    int version();

    namespace impl_simple_map { // demo; only full matches
        class index_impl;
    }

    class index {
        using index_impl = impl_simple_map::index_impl;
    public:
        index();
        ~index(); // http://stackoverflow.com/a/9064437/472245
    public:
        void add(const std::string &arg);
        std::string normalize(std::string arg) const;
        size_t size() const;
        std::string getBestMatch(const std::string& query) const;
    private:
        const std::unique_ptr<index_impl> pimpl;
    };

} // namespace qw
