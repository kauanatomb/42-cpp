#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(nullptr), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : data(new T[other.size]()), size(other.size) {
    for(size_t i = 0; i < size; i++)
        data[i] = other.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other) 
        return *this;
    delete[] data;
    size = other.size;
    data = new T[other.size]();
    for(size_t i = 0; i < other.size; i++)
        data[i] = other.data[i];
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= size)
        throw std::out_of_range("Array index out of bounds");
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= size)
        throw std::out_of_range("Array index out of bounds");
    return data[index];
}

template <typename T>
size_t Array<T>::sizeArr() const {
    return size;
}
