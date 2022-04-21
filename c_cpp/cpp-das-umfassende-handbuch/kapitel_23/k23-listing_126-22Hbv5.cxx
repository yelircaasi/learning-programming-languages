
template <typename T>
class MyContainer {
    T data_;
public:
    void setData(const T& d);
    T getData() const;
};

template <typename T>
void MyContainer<T>::setData(const T& d) {
    data_ = d;
}

template <typename T>
T MyContainer<T>::getData() const {
    return data_;
}

