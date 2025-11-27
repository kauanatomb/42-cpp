#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"

int main(void) {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(3.0f, 3.0f);
    Point outside(11.0f, 5.0f);
    Point edge(5.0f, 0.0f); // its on edge

    std::cout << std::boolalpha;

    std::cout << "Inside: " << bsp(a, b, c, inside) << "\n";
    std::cout << "Outside: " << bsp(a, b, c, outside) << "\n";
    std::cout << "On Edge: " << bsp(a, b, c, edge) << "\n";

    return 0;
}

