#include "Span.hpp"
#include <iostream>

int main() {
    std::cout << "Subject test\n";
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest: " << sp.longestSpan() << std::endl;

    std::cout << "Span test\n";
    Span sp1(10000);
    std::vector<int> v(10000);

    for (int i = 0; i < 10000; i++)
        v[i] = rand();

    sp1.addRange(v.begin(), v.end());

    std::cout << "shortest: " << sp1.shortestSpan() << std::endl;
    std::cout << "longest: " << sp1.longestSpan() << std::endl;
    return 0;
}