#ifndef AMateria_HPP
#define AMateria_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

class ICharacter;

class AMateria {
    protected:
        std::string type;
    public:
        AMateria(std::string const & type);
        virtual ~AMateria();
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
    
        std::string const & getType() const;
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif