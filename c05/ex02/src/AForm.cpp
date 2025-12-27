#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

const std::string& AForm::getName() const { return name; } 
bool AForm::getIsSigned() const  { return isSigned; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high";
};
const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low";
};

const char* AForm::AlreadySignedException::what() const throw() {
    return "AForm is already signed";
};

const char* AForm::IsNotSignedException::what() const throw() {
    return "AForm needs to be sign to execute";
};

std::ostream& operator<<(std::ostream& out, const AForm& obj) {
    out << "AForm name: " << obj.getName() << ", status: "
     << (obj.getIsSigned() ? "signed, " : "not signed, ")
     << "the required grade to sign: " << obj.getSignGrade()
     << " and the required grade to execute: " << obj.getExecGrade();
  return out;
}

void AForm::beSigned(const Bureaucrat& signer) {
    if (isSigned)
        throw AlreadySignedException();
    if (signer.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw IsNotSignedException();

    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();

    executeAction();
}
