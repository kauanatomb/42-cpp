#ifndef aform_hpp
#define aform_hpp

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        AForm(const std::string& name, int signGrade, int execGrade);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm& operator=(const AForm& other);

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

        class IsNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };

        void execute(Bureaucrat const & executor) const;

    protected:
        virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif