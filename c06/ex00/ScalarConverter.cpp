#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>
#include <iomanip>

static bool isPseudoLiteral(const std::string &s)
{
    return (s == "nan" || s == "+inf" || s == "-inf"
         || s == "nanf" || s == "+inff" || s == "-inff");
}

static void printChar(double d)
{
    std::cout << "char: ";
    if (std::isnan(d) || d < 0 || d > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'\n";
}

static void printInt(double d)
{
    std::cout << "int: ";
    if (std::isnan(d)
        || d < std::numeric_limits<int>::min()
        || d > std::numeric_limits<int>::max())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(d) << "\n";
}

static bool isInteger(double d)
{
    return d == static_cast<int>(d);
}

static void printFloat(double d)
{
    std::cout << "float: ";
    if (std::isnan(d))
        std::cout << "nanf\n";
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inff\n" : "+inff\n");
    else
    {
        float f = static_cast<float>(d);
        if (isInteger(d))
            std::cout << std::fixed << std::setprecision(1) << f << "f\n";
        else
            std::cout << f << "f\n";
    }
}

static void printDouble(double d)
{
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan\n";
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inf\n" : "+inf\n");
    else
    {
        if (isInteger(d))
            std::cout << std::fixed << std::setprecision(1) << d << "\n";
        else
            std::cout << d << "\n";
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    double value;

    /* CHAR */
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        value = static_cast<double>(literal[0]);
    }
    /* PSEUDO */
    else if (isPseudoLiteral(literal))
    {
        value = std::strtod(literal.c_str(), NULL);
    }
    /* NUMBER */
    else
    {
        char *end;
        value = std::strtod(literal.c_str(), &end);

        if (*end && *end != 'f')
        {
            std::cout << "Invalid literal\n";
            return;
        }
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
