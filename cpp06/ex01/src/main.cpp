#include "../inc/Serializer.hpp"
#include <iostream>

int main() {
    Data* check = new Data(12345, 1.2345);

    uintptr_t raw = Serializer::serialize(check);
    std::cout << "raw:   0x" << std::hex << raw << std::dec << "\n";

    Data* ret = Serializer::deserialize(raw);
    std::cout << "check: " << check << "\n";
    std::cout << "ret:   " << ret << "\n";
    std::cout << std::boolalpha << "check == ret? " << (check == ret) << "\n";

    delete check;
}
