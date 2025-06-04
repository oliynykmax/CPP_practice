#include <cstdlib>
#include <string>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(int argc, char **argv)
{
    int num = 1;
    std::string name = "Mykyta";
    if (argc >= 2)
    {
        num = atoi(argv[1]);
        if (argc >= 3)
            name = argv[2];
    }
    std::cout << "Now let's create a horde of them" << std::endl;
    Zombie* horde = zombieHorde(num, name);
    if (horde != nullptr)
    {
        for (int i = 0; i < num; i++)
            horde[i].announce();
    }
    std::cout << "Everything working, we don't need them anymore" << std::endl;
    delete[] horde;
    return (0);
}
