#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat a("Alice", 80);
    Bureaucrat b("Bob", 101);
    Bureaucrat c("Dylan", 50);

    Form f("TopSecret", 100, 50);
    Form f1("TopSecret1", 100, 90);

    std::cout << f << std::endl;
    a.signForm(f); // work
    b.signForm(f); // should fail
    b.signForm(f1); // should fail
    c.signForm(f1); // work

    std::cout << f << std::endl;
    std::cout << f1 << std::endl;
}


