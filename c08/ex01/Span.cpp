#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}
Span::~Span() {}
Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (numbers.size() >= maxSize)
        throw FullException();
    numbers.push_back(n);
}

int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}

int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> tmp(numbers);
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];

    for(size_t i = 2; i < tmp.size(); i++) {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

const char* Span::FullException::what() const throw() {
    return "Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
    return "Not enough numbers to compute span";
}