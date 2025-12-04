#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <string>
#include <iostream>

class WrongAnimal {
    protected:
        std::string type;

    public:
        WrongAnimal(const std::string& inputType);
        ~WrongAnimal();
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);

        void makeSound(void) const;
        const std::string getType() const;
};

#endif