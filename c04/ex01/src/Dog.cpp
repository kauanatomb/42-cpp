#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain)  {
    std::cout << "Dog default constructor called" << std::endl ;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called" << std::endl ;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Dog copy assignment constructor called" << std::endl ;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Dog does: Au au au\n";
}

Brain* Dog::getBrain() const {
    return brain;
}