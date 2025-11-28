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
    std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}