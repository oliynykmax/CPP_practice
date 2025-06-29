#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <memory>

int main()
{
    std::cout << "\n--- Polymorphic Animal Tests ---\n";
    std::unique_ptr<const Animal> meta = std::make_unique<Animal>();
    std::unique_ptr<const Animal> j = std::make_unique<Dog>();
    std::unique_ptr<const Animal> i = std::make_unique<Cat>();

    std::cout << "Type of j: " << j->getType() << std::endl;
    std::cout << "Type of i: " << i->getType() << std::endl;
    std::cout << "Type of meta: " << meta->getType() << std::endl;

    std::cout << "\nSounds:\n";
    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound(); // Animal sound

    std::cout << "\n--- WrongAnimal Tests (Non-Polymorphic) ---\n";
    std::unique_ptr<const WrongAnimal> wrongMeta = std::make_unique<WrongAnimal>();
    std::unique_ptr<const WrongAnimal> wrongCat = std::make_unique<WrongCat>();

    std::cout << "Type of wrongMeta: " << wrongMeta->getType() << std::endl;
    std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;

    std::cout << "\nWrong Sounds (should all be WrongAnimal sound):\n";
    wrongMeta->makeSound(); // WrongAnimal sound
    wrongCat->makeSound();   // WrongAnimal sound (due to non-polymorphic makeSound)

    std::cout << "\n--- Copy Constructor and Assignment Operator Tests ---\n";

    std::cout << "\nAnimal Copy Test:\n";
    Animal originalAnimal;
    Animal copiedAnimal = originalAnimal; // Copy constructor
    Animal assignedAnimal;
    assignedAnimal = originalAnimal; // Assignment operator

    std::cout << "Original Animal Type: " << originalAnimal.getType() << std::endl;
    std::cout << "Copied Animal Type: " << copiedAnimal.getType() << std::endl;
    std::cout << "Assigned Animal Type: " << assignedAnimal.getType() << std::endl;

    std::cout << "\nDog Copy Test:\n";
    Dog originalDog;
    Dog copiedDog = originalDog;
    Dog assignedDog;
    assignedDog = originalDog;

    std::cout << "Original Dog Type: " << originalDog.getType() << std::endl;
    std::cout << "Copied Dog Type: " << copiedDog.getType() << std::endl;
    std::cout << "Assigned Dog Type: " << assignedDog.getType() << std::endl;

    std::cout << "\nCat Copy Test:\n";
    Cat originalCat;
    Cat copiedCat = originalCat;
    Cat assignedCat;
    assignedCat = originalCat;

    std::cout << "Original Cat Type: " << originalCat.getType() << std::endl;
    std::cout << "Copied Cat Type: " << copiedCat.getType() << std::endl;
    std::cout << "Assigned Cat Type: " << assignedCat.getType() << std::endl;

    std::cout << "\nWrongAnimal Copy Test:\n";
    WrongAnimal originalWrongAnimal;
    WrongAnimal copiedWrongAnimal = originalWrongAnimal;
    WrongAnimal assignedWrongAnimal;
    assignedWrongAnimal = originalWrongAnimal;

    std::cout << "Original WrongAnimal Type: " << originalWrongAnimal.getType() << std::endl;
    std::cout << "Copied WrongAnimal Type: " << copiedWrongAnimal.getType() << std::endl;
    std::cout << "Assigned WrongAnimal Type: " << assignedWrongAnimal.getType() << std::endl;

    std::cout << "\nWrongCat Copy Test:\n";
    WrongCat originalWrongCat;
    WrongCat copiedWrongCat = originalWrongCat;
    WrongCat assignedWrongCat;
    assignedWrongCat = originalWrongCat;

    std::cout << "Original WrongCat Type: " << originalWrongCat.getType() << std::endl;
    std::cout << "Copied WrongCat Type: " << copiedWrongCat.getType() << std::endl;
    std::cout << "Assigned WrongCat Type: " << assignedWrongCat.getType() << std::endl;

    return 0;
}