#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <format>

DiamondTrap::DiamondTrap(const std::string& n)
    : ClapTrap(n + "_clap_name"), ScavTrap(n), FlagTrap(n), name(n)
{
    HitPoints = FlagTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FlagTrap::AttackDamage;
    std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << std::format("My name is {}, ClapTrap name is {} \n", DiamondTrap::name, ClapTrap::name);
}
