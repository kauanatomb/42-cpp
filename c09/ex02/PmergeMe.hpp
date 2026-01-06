#pragma once

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <cstring>
# include <cstdlib>
# include <time.h>
# include <iomanip>
# include <climits>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        void sortVector();
        void makePairs(std::vector< std::pair<int,int> >& pairs,
            bool& hasStraggler, int& straggler);
        void insertMinors(const std::vector<int>& minors,
            std::vector<int>& mainChain);
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void evaluate(int ac, char **av);
};