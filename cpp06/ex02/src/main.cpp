#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/Base.hpp"
#include "../inc/C.hpp"
#include <cctype>
#include <iostream>
#include <random>

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A\n";
  else if (dynamic_cast<B *>(p))
    std::cout << "B\n";
  else if (dynamic_cast<C *>(p))
    std::cout << "C\n";
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A\n";
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B\n";
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C\n";
    return;
  } catch (...) {
  }
}

Base *generate(void) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<int> dist(0, 2);

  switch (dist(gen)) {
  case 0:
    return new A;
  case 1:
    return new B;
  default:
    return new C;
  }
}

int main() {
  Base *ptr = generate();

  identify(ptr);
  identify(*ptr);

  Base *tr = generate();

  identify(tr);
  identify(*tr);

  Base *r = generate();

  identify(r);
  identify(*r);

  delete ptr;
}
