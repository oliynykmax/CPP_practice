#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== DiamondTrap Construction ===" << std::endl;
    DiamondTrap dt("Diamondy");

    std::cout << "\n=== DiamondTrap Actions ===" << std::endl;
    dt.attack("TargetBot");
    dt.takeDamage(20);
    dt.beRepaired(10);
    dt.whoAmI();

    std::cout << "\n=== Copy and Assignment ===" << std::endl;
    DiamondTrap dt2(dt);
    dt2.whoAmI();

    DiamondTrap dt3("AnotherOne");
    dt3 = dt;
    dt3.whoAmI();

    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}
