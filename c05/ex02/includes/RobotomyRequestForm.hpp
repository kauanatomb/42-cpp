#ifndef RobotomyRequestForm_hpp
#define RobotomyRequestForm_hpp

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
    private:
        std::string target;

    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

    protected:
        void executeAction() const;

};

#endif