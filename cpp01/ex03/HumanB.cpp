
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : name(name)  {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &newWeapon) {
	weapon = &newWeapon;
}
void HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
