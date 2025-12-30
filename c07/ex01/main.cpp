#include "iter.hpp"

int main() {
    int a[] = {1, 2, 3, 4};
    const std::string b[] = {"test1", "test2", "test3"};

    iter(a, 4, printInt);
    std::cout << std::endl;

    iter(a, 4, increment);
    iter(a, 4, print<int>);
    std::cout << std::endl;

    iter(b, 3, print<std::string>);
    std::cout << std::endl;

    return 0;
}
