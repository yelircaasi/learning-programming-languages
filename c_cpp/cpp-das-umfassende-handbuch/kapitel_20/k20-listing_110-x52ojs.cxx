#include <memory>      // unique_ptr
#include <iostream>    // cout

std::unique_ptr<int[]> createData(size_t sz) {
    return std::unique_ptr<int[]>(new int[sz]);
}

void fibonacci(int data[], int* ende) {
    for(int* p = data+2; p != ende; ++p) {
        *p = *(p-1) + *(p-2);
    }
}

std::ostream& print(std::ostream &os, int data[], int* ende) {
    for(int const* p= data; p != ende; ++p)
        std::cout << *p << " ";
    return os;
}
int main() {
    std::unique_ptr<int[]> data { createData(10) };
    data[0] = 1; // setzen Sie Werte im Array durch den unique_ptr
    data[1] = 1;
    fibonacci(data.get(), data.get()+10); // holen Sie sich den C-Array-Zeiger mit get()
    print(std::cout, data.get(), data.get()+10) << "\n";
}

