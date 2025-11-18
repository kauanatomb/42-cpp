#include "HumanA.hpp"

HumanA::HumanA(const std::string &inputName, Weapon &inputWeapon) : name(inputName), weapon(inputWeapon) {}

HumanA::~HumanA() {}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << '\n';
}
