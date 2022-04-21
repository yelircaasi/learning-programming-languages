#include <vector>
class Image {
    std::vector<unsigned char> data_;
public:
    explicit Image(const char *fn) { /*...*/ }
    Image(Image&& other) noexcept              // Verschiebekonstruktor
        : data_{} // leer erzeugen
    {
        using std::swap;
        swap(data_, other.data_);
    }
    Image& operator=(Image&& other) noexcept { // Verschiebeoperator
        using std::swap;
        swap(data_, other.data_);
        return *this;
    }
};

