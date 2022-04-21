#include <string>
#include <vector>
class Image {
    std::vector<char> bilddaten_;
public:
    explicit Image(const std::string& filename) { /* Bild laden */ }
    void draw() const { /* Bild malen */ };
};

