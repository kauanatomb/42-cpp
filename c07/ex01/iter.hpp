#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T* array, const size_t len, F func) {
    if (!array)
        return ;
    for (size_t i = 0; i < len; ++i) 
        func(array[i]);
}

void printInt(const int& x) {
    std::cout << x << " ";
}

void increment(int& x) {
    x++;
}

template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

#endif
