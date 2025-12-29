#include "Identify.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <type_traits> // apenas para dynamic_cast, sem typeinfo

Base* generate()
{
    std::srand(std::time(NULL));
    int r = std::rand() % 3;

    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}

// identify with pointer
void identify(Base* p)
{
    if (!p)
        return;

    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

// identify with ref
void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (...) {}
}
