#include "Fixed.hpp"

Fixed::Fixed() : raw(0) {}

Fixed::Fixed(const int number) {
    raw = number << fractionalBits;
}

Fixed::Fixed(const float number) {
    raw = roundf(number * ( 1 << fractionalBits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &other) : raw(other.raw) {}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->raw = other.raw;
    std::cout << "Copy assignment operator called\n";
    return *this;
}

int Fixed::getRawBits(void) const {
    return raw;
}

void Fixed::setRawBits(int const raw) {
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

Fixed& Fixed::operator++() {
    this->raw += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    this->raw += 1;
    return tmp; 
}

Fixed& Fixed::operator--() {
    this->raw -= 1;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    this->raw -= 1;
    return tmp;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.raw = this->raw + other.raw;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.raw = this->raw - other.raw;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long tmp = (long)this->raw * (long)other.raw;
    result.raw = tmp >> fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.raw == 0)
        return Fixed(0);
    Fixed result;
    long tmp = ((long)this->raw << fractionalBits) / other.raw;
    result.raw = tmp;
    return result;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->raw > other.raw;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->raw < other.raw;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->raw >= other.raw;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->raw <= other.raw;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->raw == other.raw;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->raw != other.raw;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    return (first.raw < second.raw) ? first : second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    return (first.raw > second.raw) ? first : second;
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    return (first.raw < second.raw) ? first : second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
    return (first.raw > second.raw) ? first : second;
}