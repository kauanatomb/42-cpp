#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& inputName) : ClapTrap(inputName) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScarvTrap constructed: " << name << std::endl ;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destroyed: " << name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ScavTrap " << name << " is too exhausted to attack!\n";
        return;
    }
    energyPoints--;    
    std::cout << "ScavTrap " << name
              << " attacks " << target 
              << ", giving " << attackDamage << " damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment called\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}
