#include "FragTrap.hpp"

int main() {
    std::cout << "\n=== Test 1: Construction Chain ===\n";
    FragTrap f1("Alpha");

    std::cout << "\n=== Test 2: Basic Actions ===\n";
    FragTrap f("Bravo");
    f.highFivesGuys();

    std::cout << "\n=== Test 3: Copy Constructor ===\n";
    FragTrap original("Charlie");
    FragTrap copy(original);
    copy.highFivesGuys();

    std::cout << "\n=== Test 4: Copy Assignment ===\n";
    FragTrap a("Delta");
    FragTrap b("Echo");
    b = a;
    b.highFivesGuys();

    std::cout << "\n=== Test 5: Upcasting to ClapTrap ===\n";
    FragTrap sub("Foxtrot");
    ClapTrap* basePtr = &sub;

    basePtr->attack("an enemy");
    sub.highFivesGuys();

    std::cout << "\n=== Test 6: Energy Exhaustion ===\n";
    FragTrap g("Gamma");

    for (int i = 0; i < 102; i++) {
        g.attack("dummy");
    }

    std::cout << "\n=== Test 7: HP Exhaustion ===\n";
    FragTrap h("Hotel");

    h.takeDamage(200); // HP = 0
    h.attack("nobody"); // should fail
    h.highFivesGuys();

    std::cout << "\n=== End of all tests ===\n";
    return 0;
}

