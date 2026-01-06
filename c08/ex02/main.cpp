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

    std::cout << "\nTEST: with const iterator\n";

    const MutantStack<int> cmstack = mstack;

    MutantStack<int>::const_iterator cit = cmstack.begin();
    MutantStack<int>::const_iterator cite = cmstack.end();

    while (cit != cite) {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "\nTEST: deep copy\n";

    MutantStack<int> copy(mstack);
    copy.pop();

    std::cout << "Original size: " << mstack.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;

    MutantStack<int> assign;
    assign.push(42);

    assign = mstack;
    assign.pop();

    std::cout << "Assigned size: " << assign.size() << std::endl;
    std::cout << "Original size: " << mstack.size() << std::endl;

    std::cout << "\nTEST: with string type\n";

    MutantStack<std::string> sstack;
    sstack.push("hello");
    sstack.push("world");

    for (MutantStack<std::string>::iterator it = sstack.begin();
        it != sstack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}