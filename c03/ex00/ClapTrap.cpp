#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& inputName) : name(inputName), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Constructor called for: " << name << std::endl ;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "Copy constructor called for: " << name << std::endl ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "Copy assignment constructor called for: " << name << std::endl ;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ClapTrap " << name << " has no energy or hit points left!\n";
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already destroyed!\n";
        return;
    }
    if (amount > static_cast<unsigned int>(hitPoints))
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! HP now: " << hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ClapTrap " << name
                  << " cannot repair itself (no HP or energy left).\n";
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself, +"
              << amount << " HP! HP now: " << hitPoints << "\n";
}
