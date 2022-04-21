template <typename T>
class MyContainer {
    T data_;

public:
    void setData(const T& d) { data_ = d; }
    T getData() const { return data_; }
};

