#ifndef Brain_HPP
#define Brain_HPP

#include <string>
#include <iostream>

class Brain {
    private:
        std::string ideas[100];

    public:
        Brain();
        ~Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);

        void setIdea(int index, const std::string& idea);
        const std::string& getIdea(int index) const;
};

#endif