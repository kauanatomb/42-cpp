#ifndef Animal_HPP
#define Animal_HPP

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string type;

    public:
        Animal(const std::string& inputType);
        virtual ~Animal();
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);

        virtual void makeSound(void) const = 0;
        const std::string getType() const;
};

#endif