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

static std::vector<size_t> buildJacobIndices(size_t n) {
    std::vector<size_t> res;
    if (n <= 1)
        return res;

    size_t a = 1;
    size_t b = 3;
    while (a < n) {
        res.push_back(a);
        size_t c = b + 2 * a;
        a = b;
        b = c;
    }
    return res;
}


void PmergeMe::insertMinors(const std::vector<int>& minors,
                           std::vector<int>& mainChain)
{
    std::vector<size_t> jacob = buildJacobIndices(minors.size());
    std::vector<bool> used(minors.size(), false);

    for (int i = jacob.size() - 1; i >= 0; --i) {
        size_t idx = jacob[i];
        int val = minors[idx];

        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(it, val);
        used[idx] = true;
    }

    for (int i = minors.size() - 1; i >= 0; --i) {
        if (used[i])
            continue;
        int val = minors[i];
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), val);
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

    std::cout << "After: ";
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
    
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    clock_t start = clock();
    sortVector();
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << vec.size()
          << " elements with std::vector : " 
          << duration << " us" << std::endl;
}
