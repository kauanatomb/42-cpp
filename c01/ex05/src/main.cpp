#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong number of args" << std::endl;
        return 1;
    }
    Harl a;
    a.complain(argv[1]);
    return (0);
}
