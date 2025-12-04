#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "=== Individual objects ===\n";
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    for (int k = 0; k < 2; k++)
    {
        std::cout << "Animal[" << k << "]: ";
        animals[k]->makeSound();
        std::cout << "Type: " << animals[k]->getType() << "\n";
    }

    for (int k = 0; k < 2; k++)
        delete animals[k];

    std::cout << "\n=== Copy constructor and assignment ===\n";
    Dog dog;
    Dog dog2(dog);
    dog2 = dog;
    Cat cat;
    Cat cat2(cat);
    cat2 = cat;

    return 0;
}
