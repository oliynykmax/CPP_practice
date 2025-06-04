#include <cstdlib>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump( std::string name );

int main()
{
    std::cout << "Let's test some zombies allocated on stack and heap memory"
    << std::endl;
    std::cout << "Let's test a zombies on heap memory first" << std::endl;
    Zombie *Dave = newZombie("Dave");
    Zombie *Martin = newZombie("Martin");
    Zombie *Rodger = newZombie("Robert");
    Dave->announce();
    Martin->announce();
    Rodger->announce();
    std::cout << "We no longer need them, that's why we can manualy destroy them" << std::endl;
    delete Dave;
    delete Martin;
    delete Rodger;
    std::cout << "Now let's test a zombie on stack memory" << std::endl;
    randomChump("Viktor");
    randomChump("Mykola");
    randomChump("Taras");
    std::cout << "As we can see, they were destroyed before even being returned, yay" << std::endl;
    return (0);
}
