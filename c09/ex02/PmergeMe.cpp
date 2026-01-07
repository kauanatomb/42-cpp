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

void PmergeMe::evaluate(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        char *end;
        long n = std::strtol(av[i], &end, 10);
        if (*end != '\0' || n < 0 || n > INT_MAX)
            throw std::runtime_error("Error");
        vec.push_back(static_cast<int>(n));
        deq.push_back(static_cast<int>(n));
    }
    
    PmergeMe::printContainer(vec, "Before: ");

    clock_t start_v = clock();
    sortVector();
    clock_t end_v = clock();
    clock_t start_d = clock();
    sortDeque();
    clock_t end_d = clock();
    PmergeMe::printContainer(vec, "After: ");
    PmergeMe::timerCalcPrint(start_v, end_v, vec.size(), "std::vector");
    PmergeMe::timerCalcPrint(start_d, end_d, deq.size(), "std::deque");
}

// vector
void PmergeMe::makePairsV(std::vector< std::pair<int,int> >& pairs,
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

std::vector<size_t> PmergeMe::buildJacobIndicesV(size_t n) {
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

void PmergeMe::insertMinorsV(const std::vector<int>& minors,
                           std::vector<int>& mainChain)
{
    std::vector<size_t> jacob = buildJacobIndicesV(minors.size());
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

    makePairsV(pairs, hasStraggler, straggler);

    std::vector<int> mainChain;
    std::vector<int> minors;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].second);
        minors.push_back(pairs[i].first); 
    }

    std::sort(mainChain.begin(), mainChain.end());

    insertMinorsV(minors, mainChain);

    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(),
            mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    vec.clear();
    for (size_t j = 0; j < mainChain.size(); ++j)
        vec.push_back(mainChain[j]);
}

// deque

void PmergeMe::makePairsD(std::deque< std::pair<int,int> >& pairs,
    bool& hasStraggler, int& straggler) {
    
    hasStraggler = false;
    size_t i = 0;
    for (; i + 1 < deq.size(); i += 2) {
        int a = deq[i];
        int b = deq[i + 1];

        if (a > b)
            std::swap(a, b);

        pairs.push_back(std::make_pair(a, b));
    }

    if (i < deq.size()) {
        hasStraggler = true;
        straggler = deq[i];
    }
}

std::deque<size_t> PmergeMe::buildJacobIndicesD(size_t n) {
    std::deque<size_t> res;
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

void PmergeMe::insertMinorsD(const std::deque<int>& minors,
                           std::deque<int>& mainChain)
{
    std::deque<size_t> jacob = buildJacobIndicesD(minors.size());
    std::deque<bool> used(minors.size(), false);

    for (int i = jacob.size() - 1; i >= 0; --i) {
        size_t idx = jacob[i];
        int val = minors[idx];

        std::deque<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(it, val);
        used[idx] = true;
    }

    for (int i = minors.size() - 1; i >= 0; --i) {
        if (used[i])
            continue;
        int val = minors[i];
        std::deque<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(it, val);
    }
}

void PmergeMe::sortDeque() {
    std::deque< std::pair<int,int> > pairs;
    bool hasStraggler;
    int straggler;

    makePairsD(pairs, hasStraggler, straggler);

    std::deque<int> mainChain;
    std::deque<int> minors;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].second);
        minors.push_back(pairs[i].first); 
    }

    std::sort(mainChain.begin(), mainChain.end());

    insertMinorsD(minors, mainChain);

    if (hasStraggler) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(),
            mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    deq.clear();
    for (size_t j = 0; j < mainChain.size(); ++j)
        deq.push_back(mainChain[j]);
}
