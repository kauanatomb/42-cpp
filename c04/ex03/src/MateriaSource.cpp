#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        templates[i] = NULL;
}
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete templates[i];
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource() {
    for (int i = 0; i < 4; i++)
    {
        if (other.templates[i])
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++)
        {
            delete templates[i];
            if (other.templates[i])
                templates[i] = other.templates[i]->clone();
            else
                templates[i] = NULL;
        }
    }   
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++)
    {
        if (!templates[i]) {
            templates[i] = m;
            std::cout << "Learn materia for " << m->getType() << "\n";
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] && templates[i]->getType() == type) {
            std::cout << "Create materia " << templates[i]->getType() << "\n";
            return templates[i]->clone();
        }
    }
    std::cout << "No materia found: " << type << "\n";
    return NULL;
}