#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Basic ScavTrap Construction ===\n";
    ScavTrap s1("Guardian");

    std::cout << "\n=== Attack and Special Ability ===\n";
    s1.attack("an intruder");
    s1.guardGate();

    std::cout << "\n=== Testing Copy Constructor ===\n";
    ScavTrap s2(s1);
    s2.attack("copy-target");

    std::cout << "\n=== Testing Copy Assignment ===\n";
    ScavTrap s3("Temp");
    s3 = s1;
    s3.attack("assigned-target");

    std::cout << "\n=== Check ClapTrap attack function ===\n";
    ClapTrap* basePtr = &s1;
    basePtr->attack("base-intruder");

    std::cout << "\n=== Exhausting Energy Points ===\n";
    ScavTrap attacker("Soldier");
    for (int i = 0; i < 52; ++i) {
        attacker.attack("dummy");
    }

    std::cout << "\n=== End of Scope ===" << std::endl;
    return 0;
}

