#include "Fixed.hpp"

Fixed::Fixed() : raw(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int number) {
    std::cout << "Int constructor called\n";
    raw = number << fractionalBits;
}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called\n";
    raw = roundf(number * ( 1 << fractionalBits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other) : raw(other.raw) {
    std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->raw = other.raw;
    std::cout << "Copy assignment operator called\n";
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return raw;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    this->raw = raw;
}

float Fixed::toFloat() const {
    return (float)raw / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return raw >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}
