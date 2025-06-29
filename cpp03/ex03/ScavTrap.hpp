#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string &new_name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &src);
        ~ScavTrap() override;
        void guardGate();
        void attack(const std::string &target) override;
};


#endif
