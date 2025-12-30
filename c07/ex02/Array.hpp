#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
    private:
        T* data;
        size_t size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        ~Array();

        Array& operator=(const Array& other);

        T& operator[](size_t index);
        const T& operator[](size_t index) const;

        size_t sizeArr() const;
};

#include "Array.tpp"

#endif
