#include "../inc/Array.hpp"
#include <iostream>
#include <exception>

class Awesome {
public:
    Awesome() : _n(42) {}
    Awesome(int n) : _n(n) {}
    Awesome(const Awesome &other) : _n(other._n) {}
    Awesome &operator=(const Awesome &other) {
        _n = other._n;
        return *this;
    }
    int get() const { return _n; }
private:
    int _n;
};

std::ostream &operator<<(std::ostream &os, const Awesome &a) {
    os << a.get();
    return os;
}

template <typename T>
void printArray(const Array<T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    try {
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;

        Array<int> numbers(5);
        std::cout << "Numbers array size: " << numbers.size() << std::endl;
        printArray(numbers);

        for (size_t i = 0; i < numbers.size(); ++i)
            numbers[i] = static_cast<int>(i * 10);
        printArray(numbers);

        Array<int> numbersCopy(numbers);
        std::cout << "Copy array: ";
        printArray(numbersCopy);

        numbers[0] = 999;
        std::cout << "After modifying original:" << std::endl;
        std::cout << "Original: "; printArray(numbers);
        std::cout << "Copy: "; printArray(numbersCopy);

        Array<int> assigned;
        assigned = numbers;
        std::cout << "Assigned array: ";
        printArray(assigned);

        try {
            numbers[10] = 123;
        } catch (const std::exception &e) {
            std::cout << "Caught out-of-bounds exception: " << e.what() << std::endl;
        }

        Array<Awesome> awesomeArr(3);
        for (size_t i = 0; i < awesomeArr.size(); ++i)
            awesomeArr[i] = Awesome(static_cast<int>(i * 100));
        std::cout << "Awesome array: ";
        printArray(awesomeArr);

        Array<Awesome> awesomeCopy(awesomeArr);
        Array<Awesome> awesomeAssign;
        awesomeAssign = awesomeArr;

        std::cout << "Awesome copy: ";
        printArray(awesomeCopy);
        std::cout << "Awesome assigned: ";
        printArray(awesomeAssign);
        const Array<int> constNumbers(numbers);
        std::cout << "Const array first element: " << constNumbers[0] << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
