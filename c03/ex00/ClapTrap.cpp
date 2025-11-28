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
    if (energyPoints < 0)
        energyPoints = 0;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already destroyed!\n";
        return;
    }
    int dmg = static_cast<int>(amount);
    if (dmg < 0) dmg = 0;
    hitPoints -= dmg;
    if (hitPoints < 0)
        hitPoints = 0;
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
    if (energyPoints < 0)
        energyPoints = 0;
    int heal = static_cast<int>(amount);
    if (heal < 0) heal = 0;
    hitPoints += heal;
    std::cout << "ClapTrap " << name << " repairs itself, +"
              << amount << " HP! HP now: " << hitPoints << "\n";
}

