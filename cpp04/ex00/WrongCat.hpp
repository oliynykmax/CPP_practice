#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat &src);
    WrongCat &operator=(const WrongCat &other);
    ~WrongCat();
    void makeSound() const;
    std::string getType() const;
};

#endif // WRONGCAT_HPP