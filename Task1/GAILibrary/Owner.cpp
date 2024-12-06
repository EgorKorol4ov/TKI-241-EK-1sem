#include "Owner.h"

Owner::Owner(const std::string& name, const std::string& address, const std::string& phone)
    : name(name), address(address), phone(phone) {}

void Owner::addCar(std::shared_ptr<Car> car) {
    cars.push_back(car);
    car->currentOwner = shared_from_this();
}

void Owner::removeCar(const std::shared_ptr<Car>& car) {
    cars.erase(std::remove(cars.begin(), cars.end(), car), cars.end());
    car->currentOwner.reset();
}

std::string Owner::getInfo() const {
    return "Owner: " + name + ", Address: " + address + ", Phone: " + phone;
}