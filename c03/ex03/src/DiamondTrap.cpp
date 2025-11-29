#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& inputName)
: ClapTrap(inputName + "_clap_name"), FragTrap(inputName), ScavTrap(inputName), name(inputName)
{
    this->hitPoints = FragTrap::hitPoints;      // HP FragTrap
    this->energyPoints = ScavTrap::energyPoints; // EP ScavTrap
    this->attackDamage = FragTrap::attackDamage; // AD FragTrap

    std::cout << "DiamondTrap " << name << " constructed!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other.ClapTrap::name), FragTrap(other), ScavTrap(other), name(other.name)
{
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "DiamondTrap copy constructed: " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "DiamondTrap copy assigned: " << name << std::endl;
    return *this;
}

void DiamondTrap::whoAmI() const {
    std::cout << "DiamondTrap name: " << name
              << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attackTarget(const std::string& target) {
    ScavTrap::attack(target);
}
