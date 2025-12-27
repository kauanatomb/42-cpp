#ifndef ShrubberyCreationForm_hpp
#define ShrubberyCreationForm_hpp

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string target;
    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

    protected:
        void executeAction() const;

};

#endif