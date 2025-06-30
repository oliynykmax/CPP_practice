#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FlagTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FlagTrap {
    private:
        std::string name;
    public:
    	DiamondTrap();
        DiamondTrap(const std::string &new_name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap() override;
        void attack(const std::string &target) override;
        void whoAmI();
};

#endif
