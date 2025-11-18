#include "HumanB.hpp"

HumanB::HumanB(const std::string &inputName) : name(inputName) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &inputWeapon) {
    weapon = &inputWeapon;
}

void HumanB::attack() {
    std::cout << name << " attacks with their " << (*weapon).getType() << '\n';
}
