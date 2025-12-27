#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

// ---- Static form creators ----
AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// ---- makeForm ----
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    const FormPair forms[] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPresidential}
    };

    for (size_t i = 0; i < sizeof(forms)/sizeof(forms[0]); ++i)
    {
        if (forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }

    std::cout << "Intern could not create form: " << formName << std::endl;
    return nullptr;
}
