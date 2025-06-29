#include "ScavTrap.hpp"

int main() {
    ScavTrap st("Guardian");
    st.attack("Intruder");
    st.guardGate();
    return 0;
}
