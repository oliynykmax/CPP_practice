#include "../inc/whatever.hpp"
#include <iostream>

int subject_test(void) {
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
  return 0;
}

int main() {
  std::string a = "hello";
  std::string b = "world";
  swap(a, b);
  std::cout << a << b << std::endl;
  std::cout << min(5, 44) << std::endl;
  std::cout << min(45, 44) << std::endl;
  std::cout << ::min(a, b) << std::endl;
  std::cout << ::min(b, a) << std::endl;
  std::cout << max(5, 44) << std::endl;
  std::cout << max(45, 44) << std::endl;
  std::cout << ::max(a, b) << std::endl;
  std::cout << ::max(b, a) << std::endl;
  std::cout << ::max(55, 55) << std::endl;

  std::cout << std::endl;
  subject_test();
}
