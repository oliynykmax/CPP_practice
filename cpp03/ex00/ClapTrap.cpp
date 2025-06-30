#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    :name("strudel"),
    HitPoints(10),
    EnergyPoints(10),
    AttackDamage(0)
{
    std::cout << "Plain constructor was called, wtf?" << std::endl;
}

ClapTrap::ClapTrap(const std::string &new_name)
    :name(new_name),
    HitPoints(10),
    EnergyPoints(10),
    AttackDamage(0)
{
    std::cout << "Constructor was called, new name: " << new_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : name(other.name)
    , HitPoints(other.HitPoints)
    , EnergyPoints(other.EnergyPoints)
    , AttackDamage(other.AttackDamage)
{
    std::cout << "Copy constructor was called, new name: " << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
    if (this != &src) {
        name = src.name;
        HitPoints = src.HitPoints;
        EnergyPoints = src.EnergyPoints;
        AttackDamage = src.AttackDamage;
    }
    std::cout << "Copy assignment operator was called, new name: " << name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor was called, name: " << name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (EnergyPoints > 0 && HitPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target << " causing " << AttackDamage << " points of damage!\n";
        EnergyPoints--;
    }
    else {
        std::cout << "Not enough energy or hit points" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << name << " loses " << amount << " points of hit!\n";
    HitPoints -= amount;
    if (HitPoints < 0)
        HitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (EnergyPoints > 0 && HitPoints > 0) {
            std::cout << "ClapTrap " << name << " repaired itself by " << amount << " points!\n";
            EnergyPoints--;
            HitPoints+=amount;
    }
    else {
        std::cout << "Not enough energy or hit points" << std::endl;
    }
}
