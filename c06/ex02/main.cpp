#include "Identify.hpp"
#include <iostream>

int main() {
    Base* obj = generate();

    std::cout << "identify(Base*): ";
    identify(obj);

    std::cout << "identify(Base&): ";
    identify(*obj);

    delete obj;
    return 0;
}
