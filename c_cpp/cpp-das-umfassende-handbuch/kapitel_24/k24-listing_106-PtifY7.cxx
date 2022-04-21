#include <set>
#include <vector>
#include <iostream>

template<class T> class HappsAllocator  {
public:
    using value_type = T;
    T* allocate(size_t count) {
        size_t add = sizeof(T)*count;
        std::cout << "allocate("<<add<<"/"<<(buf_.size()-current_)<<")\n";
        if(current_+add > buf_.size()) throw std::bad_alloc{};
        char* result = buf_.data()+current_;
        current_ += add;
        return reinterpret_cast<T*>(result);
    }
    void deallocate(T* p, size_t count) {
        size_t del = sizeof(T)*count;
        std::cout << "deallocate("<<del<<")\n";
        if(del==current_ && p==reinterpret_cast<T*>(buf_.data())) {
            std::cout << "...alles frei.\n";
            current_ = 0;// alles wieder freigeben
        }
    }
    HappsAllocator() : HappsAllocator{1024} {}
    explicit HappsAllocator(size_t mx)
      : buf_(mx, 0), current_{0} { }
private:
       std::vector<char> buf_;
       size_t current_;
};
int main() {
    constexpr size_t ANZ = 1*1000*1000;
    using Happs = HappsAllocator<int>;
    try {
        Happs happs(ANZ*sizeof(int)); // Allokator vorbereiten
        std::vector<int,Happs> data(happs);
        data.reserve(ANZ);            // Speicher in einem Schwung holen
        for(int val=0; val < (int)ANZ; ++val)
            data.push_back(val);
    } catch(std::bad_alloc &ex) {
        std::cout << "Speicher alle.\n";
    }
}

