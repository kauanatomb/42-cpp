#include <string>
#include <iostream>

class Harl {
    private:
        typedef void (Harl::*Action)();
        std::string levels[4];
        Action actions[4];
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};
