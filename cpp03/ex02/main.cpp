#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int main() {
    ScavTrap st("Guardian");
    st.attack("Intruder");
    st.guardGate();

    std::cout << "----- FlagTrap tests -----" << std::endl;
    FlagTrap ft("Banner");
    ft.attack("Villain");
    ft.guardGate();
    ft.highFivesGuys();

    FlagTrap ft2(ft);
    ft2.attack("Another Villain");

    FlagTrap ft3;
    ft3 = ft;
    ft3.attack("Yet Another Villain");

    return 0;
}
