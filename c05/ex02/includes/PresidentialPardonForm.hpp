#ifndef PresidentialPardonForm_hpp
#define PresidentialPardonForm_hpp

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string target;
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

    protected:
        void executeAction() const;

};

#endif