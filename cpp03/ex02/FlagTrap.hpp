#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class FlagTrap : public ClapTrap {
    public:
        FlagTrap();
        FlagTrap(const std::string &new_name);
        FlagTrap(const FlagTrap &other);
        FlagTrap &operator=(const FlagTrap &src);
        ~FlagTrap() override;
        void guardGate();
        void attack(const std::string &target) override;
        void highFivesGuys(void);
};

#endif
