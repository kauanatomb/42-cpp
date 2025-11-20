#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

int Harl::levelIndex(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
        if (levels[i] == level)
            return i;
    return -1;
}
