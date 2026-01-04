#include "MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> mstack;
    mstack.push(5); // 5
    mstack.push(17); // 5 17
    std::cout << mstack.top() << std::endl; // print 17
    mstack.pop(); // remove 17 - stack 5
    std::cout << mstack.size() << std::endl; // print 1
    mstack.push(3); // 5 3
    mstack.push(5); // 5 3 5
    mstack.push(737); // 5 3 5 737

    mstack.push(0); // 5 3 5 737 0
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl; // print 5 3 5 737 0
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}