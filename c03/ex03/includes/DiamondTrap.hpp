#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string name;
    public:
        DiamondTrap(const std::string& inputName);
        ~DiamondTrap();

        DiamondTrap(const DiamondTrap&);
        DiamondTrap& operator=(const DiamondTrap&);

        void whoAmI() const;
        void attackTarget(const std::string& target);
};

#endif