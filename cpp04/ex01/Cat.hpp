#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();
    virtual void makeSound() const override;

    private:
    Brain* _brain;

    public:
    Brain* getBrain() const;
};

#endif // CAT_HPP
