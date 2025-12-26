#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& inputName, int inputGrade) : name(inputName), grade(inputGrade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return name;
}
int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}
void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
};
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}