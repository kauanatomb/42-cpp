#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int raw;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int number);
        Fixed(const float number);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static const Fixed& min(const Fixed& first, const Fixed& second);
        static const Fixed& max(const Fixed& first, const Fixed& second);
        static Fixed& min(Fixed& first, Fixed& second);
        static Fixed& max(Fixed& first, Fixed& second);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
