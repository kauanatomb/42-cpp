#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain) {
    std::cout << "Cat default constructor called" << std::endl ;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy constructor called" << std::endl ;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Cat copy assignment constructor called" << std::endl ;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Cat does: Miau miau miau\n";
}

Brain* Cat::getBrain() const {
    return brain;
}