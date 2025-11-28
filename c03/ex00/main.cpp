#include "ClapTrap.hpp"

int main() {
    ClapTrap bot("test");

    bot.attack("target test");
    bot.takeDamage(5);
    bot.beRepaired(3);

    for (int i = 0; i < 12; i++)
        bot.attack("wall");

    bot.takeDamage(100);
    bot.attack("ghost");
    bot.beRepaired(10);

    return 0;
}