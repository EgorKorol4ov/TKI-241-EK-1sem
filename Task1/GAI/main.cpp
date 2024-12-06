#include <iostream>
#include "../GAILibrary/Database.h"

int main() {
    auto database = std::make_shared<Database>();

    auto owner1 = std::make_shared<Owner>("John Doe", "123 Elm St", "555-1234");
    auto owner2 = std::make_shared<Owner>("Jane Smith", "456 Oak St", "555-5678");

    auto car1 = std::make_shared<Car>("ABC123", "Toyota", "Corolla", "Red", "ENG123");
    auto car2 = std::make_shared<Car>("XYZ789", "Honda", "Civic", "Blue", "ENG456");
    auto car3 = std::make_shared<Car>("DEF456", "Toyota", "Camry", "Black", "ENG789");

    owner1->addCar(car1);
    owner2->addCar(car2);
    owner2->addCar(car3);

    database->addOwner(owner1);
    database->addOwner(owner2);
    database->addCar(car1);
    database->addCar(car2);
    database->addCar(car3);

    database->markCarAsStolen(car1);

    auto accident1 = std::make_shared<Accident>("2024-12-01", "Rear-end collision");
    accident1->addCar(car2);
    accident1->addCar(car3);
    database->addAccident(accident1);

    auto stolenCars = database->getStolenCars();
    std::cout << "Stolen cars:\n";
    for (const auto& car : stolenCars) {
        std::cout << car->getInfo() << '\n';
    }

    auto ownerOfCar = database->findOwnerByCar("XYZ789");
    if (ownerOfCar) {
        std::cout << "Owner of XYZ789: " << ownerOfCar->getInfo() << '\n';
    }

    return 0;
}