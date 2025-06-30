#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
    : ClapTrap("DefaultScavTrap")
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap default constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const std::string &new_name)
    : ClapTrap(new_name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called for " << name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
    ClapTrap::operator=(src);
    std::cout << "ScavTrap copy assignment operator called for " << name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (EnergyPoints > 0 && HitPoints > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target << " causing " << AttackDamage << " points of damage!\n";
        EnergyPoints--;
    }
    else {
        std::cout << "Not enough energy or hit points" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}
