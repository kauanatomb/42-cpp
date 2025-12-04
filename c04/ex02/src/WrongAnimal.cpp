#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string& inputType) : type(inputType) {
    std::cout << "WrongAnimal default constructor called for: " << type << std::endl ;
}

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constructor called" << std::endl ;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "WrongAnimal copy assignment constructor called" << std::endl ;
    return *this;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal makes sound\n";
}

const std::string WrongAnimal::getType() const {
    return this->type;
}