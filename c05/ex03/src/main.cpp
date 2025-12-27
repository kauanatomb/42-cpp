#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "Test 1: subject\n";
    Intern someRandomIntern;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    if (rrf)
    {
        std::cout << "Form created: " << rrf->getName() << std::endl;
        delete rrf;
    }
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Test 2: creating different forms\n";
    Intern intern;

    // sucesso
    AForm* f1 = intern.makeForm("shrubbery creation", "Home");
    std::cout << "Form created: " << f1->getName() << std::endl;
    delete f1;

    // sucesso
    AForm* f2 = intern.makeForm("robotomy request", "Bender");
    std::cout << "Form created: " << f2->getName() << std::endl;
    delete f2;

    // sucesso
    AForm* f3 = intern.makeForm("presidential pardon", "Arthur Dent");
    std::cout << "Form created: " << f3->getName() << std::endl;
    delete f3;

    // falha
    AForm* f4 = intern.makeForm("unknown form", "Target");
    if (!f4)
        std::cout << "returned a null ptr\n";
    delete f4;
    return 0;
}
