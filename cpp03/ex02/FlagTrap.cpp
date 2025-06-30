#include "FlagTrap.hpp"
#include <iostream>

FlagTrap::FlagTrap()
    : ClapTrap("DefaultFlagTrap")
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FlagTrap default constructor called for " << name << std::endl;
}

FlagTrap::FlagTrap(const std::string &new_name)
    : ClapTrap(new_name)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FlagTrap constructor called for " << name << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap &other)
    : ClapTrap(other)
{
    std::cout << "FlagTrap copy constructor called for " << name << std::endl;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &src) {
    ClapTrap::operator=(src);
    std::cout << "FlagTrap copy assignment operator called for " << name << std::endl;
    return *this;
}

FlagTrap::~FlagTrap() {
    std::cout << "FlagTrap destructor called for " << name << std::endl;
}

void FlagTrap::attack(const std::string& target) {
    if (EnergyPoints > 0 && HitPoints > 0) {
        std::cout << "FlagTrap " << name << " attacks " << target << " causing " << AttackDamage << " points of damage!\n";
        EnergyPoints--;
    }
    else {
        std::cout << "Not enough energy or hit points" << std::endl;
    }
}

void FlagTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}

void FlagTrap::highFivesGuys(void) {
    std::cout << "*Very positively*, can you give me a high fives?" << std::endl;
}
