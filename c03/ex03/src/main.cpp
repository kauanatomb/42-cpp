#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Basic DiamondTrap Construction ===\n";
    DiamondTrap dt("Diamondy");

    std::cout << "\n=== Identity Check ===\n";
    dt.whoAmI();
    dt.guardGate();
    dt.highFivesGuys();

    std::cout << "\n=== Attack Tests (via ScavTrap) ===\n";
    dt.attackTarget("an intruder");

    std::cout << "\n=== Copy Constructor ===\n";
    DiamondTrap copyDT(dt);
    copyDT.whoAmI();
    copyDT.attackTarget("copy-target");

    std::cout << "\n=== Copy Assignment ===\n";
    DiamondTrap assignedDT("Temp");
    assignedDT = dt;
    assignedDT.whoAmI();
    assignedDT.attackTarget("assigned-target");

    std::cout << "\n=== Exhausting Energy ===\n";
    for (int i = 0; i < 50; ++i) {
        dt.attackTarget("dummy-target");
    }

    std::cout << "\n=== End of Scope ===\n";
    return 0;
}

