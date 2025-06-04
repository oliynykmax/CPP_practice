#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

    public:
    Zombie();
    ~Zombie();
    void announce(void);
    void setName(std::string name);
    private:
    std::string name;
};



#endif
