#include "StolenCarsRegistry.h"

void StolenCarsRegistry::addCar(const std::shared_ptr<Car>& car) {
    stolenCars.push_back(car);
}

void StolenCarsRegistry::removeCar(const std::string& plate) {
    stolenCars.erase(std::remove_if(stolenCars.begin(), stolenCars.end(),
        [&plate](const std::shared_ptr<Car>& car) {
            return car->plateNumber == plate;
        }),
        stolenCars.end());
}

std::vector<std::shared_ptr<Car>> StolenCarsRegistry::getStolenCars() const {
    return stolenCars;
}

std::map<std::string, int> StolenCarsRegistry::getMostStolenBrands() const {
    std::map<std::string, int> brandCount;
    for (const auto& car : stolenCars) {
        brandCount[car->brand]++;
    }
    return brandCount;
}