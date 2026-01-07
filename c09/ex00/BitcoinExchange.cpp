#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { loadDatabase(); }
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : db(other.db) {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        db = other.db;
    return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }
    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    if (year < 1)
        return false;

    static const int daysInMonth[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

void BitcoinExchange::execute(const std::string& filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw CouldNotOpenFile();
    std::string line;
    std::getline(file, line);
    if (line != "date | value")
        throw InvalidHeaderFormat();

    while (std::getline(file, line)) {
        std::string date, valueStr;
        double price;
        std::istringstream ss(line);
        std::getline(ss, date, '|');
        std::getline(ss, valueStr);

        if (!date.empty()) {
            date.erase(0, date.find_first_not_of(" \n\r\t"));
            date.erase(date.find_last_not_of(" \n\r\t") + 1);
        }
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (!valueStr.empty())
            valueStr = valueStr.erase(0, 1);
        price = validatePrice(valueStr);
        if (price != -1) {
            double rate = getRate(date);
            std::cout << date << " => " << price << " = " << price * rate << std::endl;
        }
    }
    file.close();
}

double BitcoinExchange::getRate(const std::string& date) const
{
    std::map<std::string,double>::const_iterator it = db.find(date);
    if (it != db.end())
        return it->second;

    std::map<std::string,double>::const_iterator it2 = db.lower_bound(date);
    if (it2 == db.begin())
        return it2->second;
    --it2;
    return it2->second;
}

double BitcoinExchange::validatePrice(const std::string& priceStr) const {
    double priceValue;
    std::istringstream priceStream(priceStr);

    if (!(priceStream >> priceValue)) {
        std::cout << "Error: bad value input => " << priceStr << std::endl;
        return -1;
    }
    char c;
    if (priceStream >> c) {
        std::cout << "Error: bad value input => " << priceStr << std::endl;
        return -1;
    }

    if (priceValue < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return -1;
    }

    if (priceValue > 1000) {
        std::cout << "Error: too large number." << std::endl;
        return -1;
    }

    return priceValue;
}


void BitcoinExchange::loadDatabase() {
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw CouldNotOpenFile();

    std::string line;
    if (!std::getline(file, line) || line != "date,exchange_rate")
        throw InvalidHeaderFormat();

    while (std::getline(file, line)) {
        std::string date, price;
        std::istringstream ss(line);
        if (!std::getline(ss, date, ',') || !std::getline(ss, price))
            throw InvalidLineFormat();

        double rate;
        std::istringstream priceStream(price);
        if (!(priceStream >> rate))
            throw InvalidPriceFormat();
        db.insert(std::make_pair(date, rate));
    }
    file.close();
}

const char* BitcoinExchange::CouldNotOpenFile::what() const throw() {
    return "Could not open file";
};

const char* BitcoinExchange::InvalidHeaderFormat::what() const throw() {
    return "Invalid header format. Expected 'date,exchange_rate'";
};

const char* BitcoinExchange::InvalidLineFormat::what() const throw() {
    return "Invalid line format. Expected 'date,exchange_rate'";
};

const char* BitcoinExchange::InvalidPriceFormat::what() const throw() {
    return "Invalid date format. Expected 'YYYY-MM-DD'";
};