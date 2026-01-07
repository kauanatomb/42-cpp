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
        void makePairsV(std::vector< std::pair<int,int> >& pairs,
            bool& hasStraggler, int& straggler);
        void insertMinorsV(const std::vector<int>& minors,
            std::vector<int>& mainChain);
        std::vector<size_t> buildJacobIndicesV(size_t n);

        void sortDeque();
        void makePairsD(std::deque< std::pair<int,int> >& pairs,
            bool& hasStraggler, int& straggler);
        void insertMinorsD(const std::deque<int>& minors,
            std::deque<int>& mainChain);
        std::deque<size_t> buildJacobIndicesD(size_t n);

        template <typename Container>
        static void printContainer(const Container& c, const char* prefix = "") {
            if (prefix && prefix[0] != '\0')
                std::cout << prefix;
            for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << "\n";
        }
        static void timerCalcPrint(clock_t start, clock_t end, size_t n, const std::string& type) {
            double duration = double(end - start) / CLOCKS_PER_SEC * 1e6;
            std::cout << "Time to process a range of " << n
                    << " elements with " << type << ": "
                    << duration << " us" << std::endl;
        }
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void evaluate(int ac, char **av);
};