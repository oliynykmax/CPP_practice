#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal {
    protected:
    std::string type;
    public:
    WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &other);
    WrongAnimal(const WrongAnimal &src);
    ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;
};

#endif // ANIMAL_HPP
