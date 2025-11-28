#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap s("Guardian");

    std::cout << "\n=== Attacking ===" << std::endl;
    s.attack("an intruder");

    std::cout << "\n=== Special Mode ===" << std::endl;
    s.guardGate();

    std::cout << "\n=== End of Scope ===" << std::endl;
    return 0;
}
