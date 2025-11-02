#include "../inc/RPN.hpp"

static void error_exit(bool isbad) {
  if (!isbad)
    return;
  std::cerr << "Error" << std::endl;
  throw std::runtime_error("Invalid RPN expression");
}

float rpn_calculate(const std::string &argv) {
  std::stack<float> active_stack;

  for (char c : argv) {
    if (c == ' ') {
      continue;
    } else if (std::isdigit(c)) {
      active_stack.push(static_cast<float>(c - '0'));
    } else if (c == '*' || c == '+' || c == '-' || c == '/') {
      if (active_stack.size() >= 2) {
        float b = active_stack.top();
        active_stack.pop();
        float a = active_stack.top();
        active_stack.pop();
        switch (c) {
        case '*':
          active_stack.push(a * b);
          break;
        case '+':
          active_stack.push(a + b);
          break;
        case '-':
          active_stack.push(a - b);
          break;
        case '/':
          error_exit(b == 0);
          active_stack.push(a / b);
          break;
        }
      } else {
        error_exit(true);
      }
    } else {
      error_exit(true);
    }
  }

  error_exit(active_stack.size() != 1);
  return active_stack.top();
}
