#include "iter.hpp"

int main() {
    int a[] = {1, 2, 3, 4};
    const int b[] = {10, 20, 30};

    iter(a, 4, printInt);
    std::cout << std::endl;

    iter(a, 4, increment);
    iter(a, 4, print<int>);
    std::cout << std::endl;

    iter(b, 3, printInt);
    iter(b, 3, print<int>);
    std::cout << std::endl;

    return 0;
}
