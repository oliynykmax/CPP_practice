#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie new_dude(name);
    new_dude.announce();
}
