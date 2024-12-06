#include "Database.h"

void Database::addCar(const std::shared_ptr<Car>& car) {
    cars.push_back(car);
}

void Database::addOwner(const std::shared_ptr<Owner>& owner) {
    owners.push_back(owner);
}

void Database::addAccident(const std::shared_ptr<Accident>& accident) {
    accidents.push_back(accident);
}

void Database::markCarAsStolen(const std::shared_ptr<Car>& car) {
    stolenCarsRegistry.addCar(car);
}

void Database::unmarkCarAsStolen(const std::string& plate) {
    stolenCarsRegistry.removeCar(plate);
}

std::shared_ptr<Car> Database::findCarByPlate(const std::string& plate) const {
    for (const auto& car : cars) {
        if (car->plateNumber == plate)
            return car;
    }
    return nullptr;
}

std::shared_ptr<Owner> Database::findOwnerByCar(const std::string& plate) const {
    auto car = findCarByPlate(plate);
    if (car && !car->currentOwner.expired())
        return car->currentOwner.lock();
    return nullptr;
}

std::shared_ptr<Car> Database::findCarByEngineNumber(const std::string& engineNumber) const {
    for (const auto& car : cars) {
        if (car->engineNumber == engineNumber)
            return car;
    }
    return nullptr;
}

std::vector<std::shared_ptr<Car>> Database::getStolenCars() const {
    return stolenCarsRegistry.getStolenCars();
}

std::map<std::string, int> Database::getMostStolenBrands() const {
    return stolenCarsRegistry.getMostStolenBrands();
}