#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main()
{
    std::cout << "\n--- Testing Animal Array ---\n";
    Animal *zoo[20];
    for (int i = 0; i < 10; i++){
        zoo[i] = new Dog();
    }
    for (int i = 10; i < 20; i++){
        zoo[i] = new Cat();
    }
    for (int i = 0; i < 20; i++){
        delete zoo[i];
    }
    std::cout << "--- End Testing Animal Array ---\n\n";
    std::cout << "\n--- Testing Deep Copy for Dog ---\n";
    Dog originalDog;
    originalDog.getBrain()->ideas[0] = "Original Dog Idea";
    std::cout << "Original Dog's idea: " << originalDog.getBrain()->ideas[0] << std::endl;

    Dog copiedDog = originalDog;
    copiedDog.getBrain()->ideas[0] = "Copied Dog Idea"; // Modify the copy's brain
    std::cout << "Copied Dog's idea: " << copiedDog.getBrain()->ideas[0] << std::endl;
    std::cout << "Original Dog's idea after copy modification: " << originalDog.getBrain()->ideas[0] << std::endl;
    std::cout << "--- End Testing Deep Copy for Dog ---\n\n";

    // Test deep copy for Cat
    std::cout << "\n--- Testing Deep Copy for Cat ---\n";
    Cat originalCat;
    originalCat.getBrain()->ideas[0] = "Original Cat Idea";
    std::cout << "Original Cat's idea: " << originalCat.getBrain()->ideas[0] << std::endl;

    Cat copiedCat = originalCat;
    copiedCat.getBrain()->ideas[0] = "Copied Cat Idea"; // Modify the copy's brain
    std::cout << "Copied Cat's idea: " << copiedCat.getBrain()->ideas[0] << std::endl;
    std::cout << "Original Cat's idea after copy modification: " << originalCat.getBrain()->ideas[0] << std::endl;
    std::cout << "--- End Testing Deep Copy for Cat ---\n\n";

    return 0;
}
