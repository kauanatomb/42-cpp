#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

void PmergeMe::makePairs(std::vector< std::pair<int,int> >& pairs,
    bool& hasStraggler, int& straggler) {
    hasStraggler = false;

    size_t i = 0;
    for (; i + 1 < vec.size(); i += 2) {
        int a = vec[i];
        int b = vec[i + 1];

        if (a > b)
            std::swap(a, b);

        pairs.push_back(std::make_pair(a, b));
    }

    if (i < vec.size()) {
        hasStraggler = true;
        straggler = vec[i];
    }
}

void PmergeMe::insertMinors(const std::vector<int>& minors,
        std::vector<int>& mainChain) {
    std::vector<int> jacob;
    size_t n = minors.size();

    size_t a = 0, b = 1;
    while (b < n) {
        jacob.push_back(b);
        size_t c = b + 2*a;
        a = b;
        b = c;
    }

    if (n > 0)
        jacob.push_back(0);

    for (int i = minors.size() - 1; i >= 0; --i) {
        int val = minors[i];
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(),
            mainChain.end(), val);
        mainChain.insert(it, val);
    }
}

void PmergeMe::sortVector() {
    std::vector< std::pair<int,int> > pairs;
    bool hasStraggler;
    int straggler;

    makePairs(pairs, hasStraggler, straggler);

    std::vector<int> mainChain;
    std::vector<int> minors;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].second);
        minors.push_back(pairs[i].first); 
    }

    std::sort(mainChain.begin(), mainChain.end());

    insertMinors(minors, mainChain);
    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(),
            mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    std::cout << "Sorted sequence: ";
    for (size_t i = 0; i < mainChain.size(); ++i)
        std::cout << mainChain[i] << " ";
    std::cout << "\n";
}

void PmergeMe::evaluate(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        char *end;
        long n = std::strtol(av[i], &end, 10);

        if (*end != '\0' || n < 0 || n > INT_MAX)
            throw std::runtime_error("Error");

        vec.push_back(static_cast<int>(n));
    }

    if (vec.size() < 2)
        throw std::runtime_error("Error");

    sortVector();
}
