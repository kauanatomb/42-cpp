#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <map>
#include <string>
#include <exception>
#include <iostream>
# include <fstream>
# include <sstream>

class BitcoinExchange {
    private:
        std::map<std::string, double> db;

        void loadDatabase();
        void processLine(const std::string& line) const ;
        bool isValidDate(const std::string& date) const ;
        double getRate(const std::string& date) const ;
        double validatePrice(const std::string& priceStr) const ;
    public:
        BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		~BitcoinExchange();

        void execute(const std::string& filename) const ;

        class CouldNotOpenFile : public std::exception {
            public:
                const char* what() const throw();
        };

        class InvalidHeaderFormat : public std::exception {
            public:
                const char* what() const throw();
        };

        class InvalidLineFormat : public std::exception {
            public:
                const char* what() const throw();
        };

        class InvalidPriceFormat : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif