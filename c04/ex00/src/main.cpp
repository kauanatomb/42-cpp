#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {
    std::cout << "=== Individual objects ===\n";
    Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();

    for (int k = 0; k < 3; k++)
    {
        std::cout << "Animal[" << k << "]: ";
        animals[k]->makeSound();
        std::cout << "Type: " << animals[k]->getType() << "\n";
    }

    for (int k = 0; k < 3; k++)
        delete animals[k];

    std::cout << "\n=== Wrong objects ===\n";
    WrongAnimal* w_animals[2];
    w_animals[0] = new WrongAnimal();
    w_animals[1] = new WrongCat();

    for (int k = 0; k < 2; k++)
    {
        std::cout << "Animal[" << k << "]: ";
        w_animals[k]->makeSound();
        std::cout << "Type: " << w_animals[k]->getType() << "\n";
    }

    for (int k = 0; k < 2; k++)
        delete w_animals[k];

    std::cout << "\n=== Copy constructor and assignment ===\n";
    Animal a;
    Animal b(a);
    b = a;
    Dog dog;
    Dog dog2(dog);
    dog2 = dog;
    Cat cat;
    Cat cat2(cat);
    cat2 = cat;
    WrongAnimal c;
    WrongAnimal d(c);
    d = c;
    WrongCat wCat;
    WrongCat wCat2(wCat);
    wCat2 = wCat;

    return 0;
}