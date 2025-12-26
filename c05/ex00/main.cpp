#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Valid construction ===\n";
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
        Bureaucrat b(a);
        std::cout << b << std::endl;
        Bureaucrat c("Junior", 50);
        std::cout << c << std::endl;
        c = a;
        std::cout << c << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid construction (too high) ===\n";
    try {
        Bureaucrat b("Bob", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid construction (too low) ===\n";
    try {
        Bureaucrat c("Charlie", 151);
        std::cout << c << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Increment grade ===\n";
    try {
        Bureaucrat d("Diana", 2);
        std::cout << d << std::endl;
        d.incrementGrade();
        std::cout << d << std::endl;
        d.incrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Decrement grade ===\n";
    try {
        Bureaucrat e("Edward", 149);
        std::cout << e << std::endl;
        e.decrementGrade();
        std::cout << e << std::endl;
        e.decrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

