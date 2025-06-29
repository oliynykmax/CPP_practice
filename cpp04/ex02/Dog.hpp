
#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();
    virtual void makeSound() const override;

    private:
    Brain* _brain;

    public:
    Brain* getBrain() const;
};

#endif // DOG_HPP
