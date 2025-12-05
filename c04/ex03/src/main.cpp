#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

// int main() {
//     std::cout << "===== TEST 1: MateriaSource basic =====\n";
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     src->learnMateria(NULL);
//     src->learnMateria(new Ice());

//     AMateria* tmp;

//     std::cout << "\n===== TEST 2: equip and use =====\n";
//     Character* me = new Character("me");

//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     AMateria* firstIce = tmp;

//     tmp = src->createMateria("cure");
//     me->equip(tmp);

//     tmp = src->createMateria("unknown"); // should return nothing
//     me->equip(tmp);                      // shouldnt crash

//     Character* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     me->use(3, *bob); // slot empty nothing happens

//     std::cout << "\n===== TEST 3: unequip without delete =====\n";
//     me->unequip(0);
//     delete firstIce;

//     std::cout << "\n===== TEST 4: fullfil table =====\n";
//     me->equip(src->createMateria("cure"));
//     me->equip(src->createMateria("ice"));

//     std::cout << "\n===== TEST 5: copy constructor =====\n";
//     Character clone(*me);
//     clone.use(0, *bob);

//     std::cout << "\n===== TEST 6: copy assign =====\n";
//     Character other("other");
//     other = clone;
//     other.use(1, *bob);

//     std::cout << "\n===== TEST 7: full table =====\n";
//     Character full("full");
//     for (int i = 0; i < 4; i++)
//         full.equip(src->createMateria("ice"));

//     AMateria* extra = src->createMateria("ice");
//     full.equip(extra); // should ignore
//     delete extra;

//     std::cout << "\n===== CLEANUP =====\n";
//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}