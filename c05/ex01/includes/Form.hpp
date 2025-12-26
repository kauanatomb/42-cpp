#ifndef form_hpp
#define form_hpp

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        Form(const std::string& name, int signGrade, int execGrade);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);

        const std::string& getName() const ;
        bool getIsSigned() const ;
        int getSignGrade() const ;
        int getExecGrade() const ;

        void beSigned(const Bureaucrat& signer);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class AlreadySignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif