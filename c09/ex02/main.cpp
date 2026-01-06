#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cerr << "Error\n";
        return 1;
    }

    try {
        PmergeMe p;
        p.evaluate(ac, av);
    } catch (const std::exception&) {
        std::cerr << "Error\n";
        return 1;
    }
}