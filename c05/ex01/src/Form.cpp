#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

const std::string& Form::getName() const { return name; } 
bool Form::getIsSigned() const  { return isSigned; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
};
const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
};

const char* Form::AlreadySignedException::what() const throw() {
    return "Form is already signed";
};

std::ostream& operator<<(std::ostream& out, const Form& obj) {
    out << "Form name: " << obj.getName() << ", status: "
     << (obj.getIsSigned() ? "signed, " : "not signed, ")
     << "the required grade to sign: " << obj.getSignGrade()
     << " and the required grade to execute: " << obj.getExecGrade();
  return out;
}

void Form::beSigned(const Bureaucrat& signer) {
    if (isSigned)
        throw AlreadySignedException();
    if (signer.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}