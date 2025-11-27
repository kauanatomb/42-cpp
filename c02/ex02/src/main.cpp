#include "Fixed.hpp"

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int main() {
    std::cout << "--- Constructors ---\n";
    Fixed a;                    // Default
    Fixed const b(10);          // Int constructor
    Fixed const c(42.42f);      // Float constructor
    Fixed d(b);                 // Copy constructor
    a = Fixed(1234.4321f);      // Assignment

    std::cout << "\n--- Print values ---\n";
    std::cout << "a: " << a << " | int: " << a.toInt() << "\n";
    std::cout << "b: " << b << " | int: " << b.toInt() << "\n";
    std::cout << "c: " << c << " | int: " << c.toInt() << "\n";
    std::cout << "d: " << d << " | int: " << d.toInt() << "\n";

    std::cout << "\n--- Increment/Decrement ---\n";
    std::cout << "++a: " << ++a << "\n";
    std::cout << "a++: " << a++ << "\n";
    std::cout << "--a: " << --a << "\n";
    std::cout << "a--: " << a-- << "\n";
    std::cout << "a final: " << a << "\n";

    std::cout << "\n--- Arithmetic ---\n";
    Fixed sum = b + c;
    Fixed diff = c - b;
    Fixed prod = b * c;
    Fixed quot = c / b;
    std::cout << "b + c: " << sum << "\n";
    std::cout << "c - b: " << diff << "\n";
    std::cout << "b * c: " << prod << "\n";
    std::cout << "c / b: " << quot << "\n";

    std::cout << "\n--- Comparison ---\n";
    std::cout << std::boolalpha;
    std::cout << "b > c: " << (b > c) << "\n";
    std::cout << "b < c: " << (b < c) << "\n";
    std::cout << "b >= d: " << (b >= d) << "\n";
    std::cout << "b <= d: " << (b <= d) << "\n";
    std::cout << "b == d: " << (b == d) << "\n";
    std::cout << "b != c: " << (b != c) << "\n";

    std::cout << "\n--- Min/Max ---\n";
    std::cout << "min(a, c): " << Fixed::min(a, c) << "\n";
    std::cout << "max(a, c): " << Fixed::max(a, c) << "\n";
    std::cout << "min(b, d): " << Fixed::min(b, d) << "\n";
    std::cout << "max(b, d): " << Fixed::max(b, d) << "\n";

    return 0;
}
