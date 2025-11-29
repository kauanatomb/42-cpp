#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap(const std::string& inputName);
        ~FragTrap();

        FragTrap(const FragTrap&);
        FragTrap& operator=(const FragTrap&);

        void highFivesGuys(void);
};

#endif