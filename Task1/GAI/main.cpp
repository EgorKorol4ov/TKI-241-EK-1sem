#include <iostream>
#include "../GAILibrary/Owner.h"
#include "../GAILibrary/Car.h"

int main() 
{
    auto owner = std::make_shared<Owner>("John Doe", "123 Main St", "+123456789");

    auto car = std::make_shared<Car>("ABC123", "Toyota", "Corolla", "Red", "ENG123456", owner);

    car->addAccident("Minor scratch on rear bumper.");
    car->addAccident("Broken headlight after collision with pole.");

    std::cout << owner->getInfo() << "\n";
    std::cout << car->getInfo() << "\n";

    std::cout << "Accidents:\n" << car->getAccidentsInfo();

    return 0;
}