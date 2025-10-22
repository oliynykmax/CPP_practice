#pragma once
#include <stack>

template <class T> class MutantStack : public std::stack<T> {
public:
  MutantStack() = default;
  MutantStack(const MutantStack &other) = default;
  MutantStack &operator=(const MutantStack &other) = default;
  ~MutantStack() = default;

  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  iterator begin() { return std::stack<T>::c.begin(); }
  iterator end() { return std::stack<T>::c.end(); }
  const_iterator begin() const { return std::stack<T>::c.begin(); }
  const_iterator end() const { return std::stack<T>::c.end(); }
};
