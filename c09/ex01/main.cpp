#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Error\n";
        return 1;
    }

    try {
        RPN rpn;
        std::cout << rpn.evaluate(av[1]) << std::endl;
    } catch (const std::exception&) {
        std::cerr << "Error\n";
        return 1;
    }
}
