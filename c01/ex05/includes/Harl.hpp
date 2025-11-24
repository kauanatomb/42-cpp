#include <string>
#include <iostream>

class Harl {
    private:
        void (Harl::*actions[4])();
        std::string levels[4];
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};
