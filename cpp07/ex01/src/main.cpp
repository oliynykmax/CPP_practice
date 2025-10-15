#include <iostream>
#include "../inc/iter.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    ::iter(arr, 5, bar);
    std::cout << std::endl;

    double darr[] = {1.5, 2.5, 3.5};
    ::iter(darr, 3, bar);
    std::cout << std::endl;
    return 0;
}
