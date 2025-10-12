#include "../inc/Data.hpp"

Data::Data(int num, double det) : numbers(num), details(det) {}

int Data::getNumber() const { return numbers; }

double Data::getDetails() const { return details; }
