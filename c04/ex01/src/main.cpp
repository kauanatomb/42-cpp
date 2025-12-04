#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "=== TESTE 1: Animal arrays ===\n";
    {
        const int size = 4;
        Animal* animals[size];

        for (int i = 0; i < size; i++) {
            if (i < size / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        for (int i = 0; i < size; i++)
            delete animals[i];
    }

    std::cout << "\n=== TESTE 2: DEEP COPY DOG ===\n";
    {
        Dog original;
        original.getBrain()->setIdea(0, "Chase motorcycle");
        original.getBrain()->setIdea(1, "Dig holes");
        Dog copy = original;

        copy.getBrain()->setIdea(0, "Eat flip flops");

        std::cout << "Original[0] = "
                  << original.getBrain()->getIdea(0) << "\n";

        std::cout << "Copy[0]     = "
                  << copy.getBrain()->getIdea(0) << "\n";
    }

    std::cout << "\n=== TESTE 3: DEEP COPY ASSIGNMENT ===\n";
    {
        Dog a;
        a.getBrain()->setIdea(0, "Guard house");

        Dog b;
        b = a;

        b.getBrain()->setIdea(0, "Sleep on couch");

        std::cout << "a[0] = " << a.getBrain()->getIdea(0) << "\n";
        std::cout << "b[0] = " << b.getBrain()->getIdea(0) << "\n";
    }

    return 0;
}
