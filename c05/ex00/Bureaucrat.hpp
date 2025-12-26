#ifndef bureaucrat_hpp
#define bureaucrat_hpp

#include <string>
#include <iostream>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(const std::string& inputName, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif