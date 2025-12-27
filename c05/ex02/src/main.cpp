#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "-------------------------------------------------\n";
    std::cout << "Test 1: PresidentialPardonForm (success)\n";
    Bureaucrat boss("Boss", 1);
    PresidentialPardonForm p("Arthur Dent");

    boss.signForm(p);
    boss.executeForm(p);
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Test 2: ShrubberyCreationForm (fail if not signed)\n";
    Bureaucrat boss1("Boss1", 1);
    ShrubberyCreationForm s("garden");

    boss1.executeForm(s);
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Test 3: RobotomyRequestForm (signed, grade too low to exec)\n";
    Bureaucrat mid("Mid", 70);
    RobotomyRequestForm r0("park");

    mid.signForm(r0);
    mid.executeForm(r0);
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Test 4: RobotomyRequestForm (cannot sign due to low grade)\n";
    Bureaucrat low("Low", 150);
    RobotomyRequestForm r("Marvin");

    low.signForm(r);
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Test 5: RobotomyRequestForm (random success/fail)\n";
    Bureaucrat boss2("Boss2", 1);
    RobotomyRequestForm r1("Bender");

    boss2.signForm(r1);
    for (int i = 0; i < 3; ++i)
        boss2.executeForm(r1);
    std::cout << "-------------------------------------------------\n\n";

    std::cout << "Test 6: Polymorphic execution of multiple forms\n";
    Bureaucrat boss3("Boss3", 1);
    AForm* forms[3];
    forms[0] = new ShrubberyCreationForm("home");
    forms[1] = new RobotomyRequestForm("HAL");
    forms[2] = new PresidentialPardonForm("Ford Prefect");

    for (int i = 0; i < 3; ++i)
    {
        boss3.signForm(*forms[i]);
        boss3.executeForm(*forms[i]);
        delete forms[i];
    }
    std::cout << "-------------------------------------------------\n";

    return 0;
}