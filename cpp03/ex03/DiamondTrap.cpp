#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


DiamondTrap::DiamondTrap()
    : ClapTrap("DiamondTrap_clap_name"), ScavTrap("DiamondTrap"), FlagTrap("DiamondTrap"), name("DiamondTrap")
{
    HitPoints = FlagTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FlagTrap::AttackDamage;
    std::cout << "DiamondTrap default constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& n)
    : ClapTrap(n + "_clap_name"), ScavTrap(n), FlagTrap(n), name(n)
{
    HitPoints = FlagTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FlagTrap::AttackDamage;
    std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FlagTrap(other), name(other.name)
{
    HitPoints = other.HitPoints;
    EnergyPoints = other.EnergyPoints;
    AttackDamage = other.AttackDamage;
    std::cout << "DiamondTrap copy constructor called for " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FlagTrap::operator=(other);
        name = other.name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    std::cout << "DiamondTrap copy assignment operator called for " << name << std::endl;
    return *this;
}


DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My name is " << name << ", ClapTrap name is " << ClapTrap::name << " \n";
}
