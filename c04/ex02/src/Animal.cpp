#include "Animal.hpp"

Animal::Animal(const std::string& inputType) : type(inputType) {
    std::cout << "Animal default constructor called for: " << type << std::endl ;
}

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl ;
}

Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl ;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal copy assignment constructor called" << std::endl ;
    return *this;
}

const std::string Animal::getType() const {
    return this->type;
}