#include "../inc/easyfind.hpp"
#include <array>
#include <iostream>
#include <list>
#include <vector>

int main() {
  const std::vector<int> vec = {1, 2, 3, 4, 5};
  std::cout << *easyfind(vec, 3) << std::endl;
  try {
    easyfind(vec, 6);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::vector<char> vecc = {'a', 'b', 'c', 'd', 'e'};
  std::cout << *easyfind(vecc, 'd') << std::endl;
  try {
    easyfind(vecc, 'f');
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::string veccc = "world";
  std::cout << *easyfind(veccc, 'd') << std::endl;
  try {
    easyfind(veccc, 'f');
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  {
    std::vector<int> v = {1, 2, 3, 4, 5};
    const std::vector<int> cv = {6, 7, 8, 9, 10};
    std::list<int> l = {10, 20, 30};
    std::array<int, 4> a = {11, 22, 33, 44};

    std::cout << *easyfind(v, 3) << '\n';
    std::cout << *easyfind(cv, 9) << '\n';
    std::cout << *easyfind(l, 30) << '\n';
    std::cout << *easyfind(a, 44) << '\n';

    try {
      easyfind(v, 99);
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
    try {
      easyfind(cv, 99);
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
    try {
      easyfind(l, 99);
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
    try {
      easyfind(a, 99);
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }

    return 0;
  }

  return 0;
}
