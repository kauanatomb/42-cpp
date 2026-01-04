#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <cstddef>

class Span {
    private:
        unsigned int        maxSize;
        std::vector<int>    numbers;

    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int n);

        int shortestSpan() const;
        int longestSpan() const;

        template <typename It>
        void addRange(It begin, It end) {
            while (begin != end) {
                addNumber(*begin);
                ++begin;
            }
        }

        class FullException : public std::exception {
        public:
            const char* what() const throw();
        };

        class NotEnoughNumbersException : public std::exception {
        public:
            const char* what() const throw();
        };
};

#endif
