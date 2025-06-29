#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
    protected:
        std::string name;
        int HitPoints;
        int EnergyPoints;
        int AttackDamage;
    public:
        ClapTrap();
        ClapTrap(const std::string &new_name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &src);
        virtual ~ClapTrap();
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif
