#include "../inc/MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  std::cout << "----- std::list comparison -----" << std::endl;

  std::list<int> lst;
  lst.push_back(5);
  lst.push_back(17);
  std::cout << lst.back() << std::endl;
  lst.pop_back();
  std::cout << lst.size() << std::endl;
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(0);
  std::list<int>::iterator lit = lst.begin();
  std::list<int>::iterator lite = lst.end();
  ++lit;
  --lit;
  while (lit != lite) {
    std::cout << *lit << std::endl;
    ++lit;
  }
  {
    MutantStack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    std::cout << "Top: " << s1.top() << std::endl;
    s1.pop();
    std::cout << "Size after pop: " << s1.size() << std::endl;
    for (auto it = s1.begin(); it != s1.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;

    const MutantStack<int> s2 = s1;
    for (auto it = s2.begin(); it != s2.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;

    MutantStack<int> s3;
    for (int i = 0; i < 5; ++i)
      s3.push(i * 2);
    MutantStack<int> s4 = s3;
    std::cout << "Copy equal: " << (s4.size() == s3.size()) << std::endl;

    std::cout << "Forward: ";
    for (auto it = s3.begin(); it != s3.end(); ++it)
      std::cout << *it << " ";
    std::cout << "\nReverse: ";
    for (auto it = s3.end(); it != s3.begin();) {
      --it;
      std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<std::string> sstr;
    sstr.push("one");
    sstr.push("two");
    sstr.push("three");
    for (auto it = sstr.begin(); it != sstr.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;

    MutantStack<double> sd;
    for (double i = 0.5; i < 3.0; i += 0.5)
      sd.push(i);
    double sum = 0;
    for (auto it = sd.begin(); it != sd.end(); ++it)
      sum += *it;
    std::cout << "Sum: " << sum << std::endl;

    MutantStack<int> empty;
    std::cout << "Empty: " << empty.empty() << std::endl;
    empty.push(42);
    std::cout << "Empty after push: " << empty.empty() << std::endl;
  }
  return 0;
}
