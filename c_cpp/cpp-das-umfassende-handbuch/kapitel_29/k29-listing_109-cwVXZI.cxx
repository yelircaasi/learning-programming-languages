// .. includes ...
#include <thread> 
using namespace std::chrono; // seconds, suffix s
struct Image {
    std::vector<char> data_; // Kopie teuer
    explicit Image() : data_(1'000'000) {}
};
void zeigeImage(Image img) {
    std::cout << img.data_.size() << '\n';
}
void zeigeIptr(std::unique_ptr<int> iptr) {
    std::cout << *iptr << '\n';
}
int main() {
    // teuer zu kopieren, aber dafür gut zu verschieben:
    Image image{};
    std::cout << image.data_.size() << std::endl;    // Ausgabe: 1000000
    std::thread th1{ zeigeImage, std::move(image) }; // Ausgabe: 1000000
    std::this_thread::sleep_for(1s);
    std::cout << image.data_.size() << std::endl;    // Ausgabe: 0
    th1.join();
    // unmöglich zu kopieren, aber gut zu verschieben:
    auto iptr = std::make_unique<int>( 657 );
    std::cout << (bool)iptr << std::endl;            // Ausgabe: 1 für wahr
    std::thread th2{ zeigeIptr, std::move(iptr) };   // Ausgabe: 657
    std::this_thread::sleep_for(1s);
    std::cout << (bool)iptr.get() << std::endl;      // Ausgabe: 0 für falsch
    th2.join();
}

