#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    std::cout << "=== FIXED POINT ARITHMETIC TESTER ===" << std::endl << std::endl;
    
    // Test constructors
    std::cout << "--- Testing Constructors ---" << std::endl;
    Fixed a;                    // Default constructor
    Fixed b(42);               // Int constructor
    Fixed c(42.42f);           // Float constructor
    Fixed d(c);                // Copy constructor
    
    std::cout << "a (default): " << a << std::endl;
    std::cout << "b (int 42): " << b << std::endl;
    std::cout << "c (float 42.42f): " << c << std::endl;
    std::cout << "d (copy of c): " << d << std::endl << std::endl;
    
    // Test assignment operator
    std::cout << "--- Testing Assignment ---" << std::endl;
    a = Fixed(10.5f);
    std::cout << "a = 10.5f: " << a << std::endl << std::endl;
    
    // Test arithmetic operators
    std::cout << "--- Testing Arithmetic Operators ---" << std::endl;
    Fixed x(10.5f);
    Fixed y(2.25f);
    
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl << std::endl;
    
    // Test compound assignment operators
    std::cout << "--- Testing Compound Assignment ---" << std::endl;
    Fixed temp = x;
    std::cout << "temp = " << temp << std::endl;
    temp += y;
    std::cout << "temp += y: " << temp << std::endl;
    temp -= y;
    std::cout << "temp -= y: " << temp << std::endl;
    temp *= Fixed(2);
    std::cout << "temp *= 2: " << temp << std::endl;
    temp /= Fixed(2);
    std::cout << "temp /= 2: " << temp << std::endl << std::endl;
    
    // Test increment/decrement operators
    std::cout << "--- Testing Increment/Decrement ---" << std::endl;
    Fixed counter(5.5f);
    std::cout << "counter = " << counter << std::endl;
    std::cout << "++counter: " << ++counter << std::endl;
    std::cout << "counter: " << counter << std::endl;
    std::cout << "counter++: " << counter++ << std::endl;
    std::cout << "counter: " << counter << std::endl;
    std::cout << "--counter: " << --counter << std::endl;
    std::cout << "counter: " << counter << std::endl;
    std::cout << "counter--: " << counter-- << std::endl;
    std::cout << "counter: " << counter << std::endl << std::endl;
    
    // Test comparison operators
    std::cout << "--- Testing Comparison Operators ---" << std::endl;
    Fixed p(5.5f);
    Fixed q(3.3f);
    Fixed r(5.5f);
    
    std::cout << "p = " << p << ", q = " << q << ", r = " << r << std::endl;
    std::cout << "p > q: " << (p > q ? "true" : "false") << std::endl;
    std::cout << "p < q: " << (p < q ? "true" : "false") << std::endl;
    std::cout << "p >= r: " << (p >= r ? "true" : "false") << std::endl;
    std::cout << "p <= q: " << (p <= q ? "true" : "false") << std::endl;
    std::cout << "p == r: " << (p == r ? "true" : "false") << std::endl;
    std::cout << "p != q: " << (p != q ? "true" : "false") << std::endl << std::endl;
    
    // Test static min/max functions
    std::cout << "--- Testing Static Min/Max Functions ---" << std::endl;
    Fixed num1(42.42f);
    Fixed num2(21.21f);
    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
    std::cout << "Fixed::max(num1, num2) = " << Fixed::max(num1, num2) << std::endl;
    std::cout << "Fixed::min(num1, num2) = " << Fixed::min(num1, num2) << std::endl << std::endl;
    
    // Test the original subject requirement
    std::cout << "--- Original Subject Test ---" << std::endl;
    Fixed orig_a;
    Fixed const orig_b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << "a: " << orig_a << std::endl;
    std::cout << "++a: " << ++orig_a << std::endl;
    std::cout << "a: " << orig_a << std::endl;
    std::cout << "a++: " << orig_a++ << std::endl;
    std::cout << "a: " << orig_a << std::endl;
    std::cout << "b: " << orig_b << std::endl;
    std::cout << "Fixed::max( a, b ): " << Fixed::max( orig_a, orig_b ) << std::endl << std::endl;
    
    // Test edge cases
    std::cout << "--- Testing Edge Cases ---" << std::endl;
    Fixed zero(0);
    Fixed negative(-5.5f);
    Fixed small(0.125f);  // 1/8, should be exact in 8-bit fractional
    
    std::cout << "zero = " << zero << std::endl;
    std::cout << "negative = " << negative << std::endl;
    std::cout << "small = " << small << std::endl;
    std::cout << "negative + 10 = " << (negative + Fixed(10)) << std::endl;
    std::cout << "small * 8 = " << (small * Fixed(8)) << std::endl;
    std::cout << "Fixed::max(negative, zero) = " << Fixed::max(negative, zero) << std::endl;
    std::cout << "Fixed::min(negative, zero) = " << Fixed::min(negative, zero) << std::endl << std::endl;
    
    // Test conversion functions
    std::cout << "--- Testing Conversion Functions ---" << std::endl;
    Fixed conv(42.75f);
    std::cout << "conv = " << conv << std::endl;
    std::cout << "conv.toInt() = " << conv.toInt() << std::endl;
    std::cout << "conv.toFloat() = " << conv.toFloat() << std::endl;
    std::cout << "conv.getRawBits() = " << conv.getRawBits() << std::endl;
    
    Fixed raw_test;
    raw_test.setRawBits(1024);  // Should represent 4.0 (1024 / 256)
    std::cout << "After setRawBits(1024): " << raw_test << std::endl;
    
    std::cout << std::endl << "=== ALL TESTS COMPLETED ===" << std::endl;
    
    return 0;
}