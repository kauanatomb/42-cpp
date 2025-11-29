#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& inputName) : ClapTrap(inputName) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructed: " << name << std::endl ;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destroyed: " << name << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a high five!\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment called\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}