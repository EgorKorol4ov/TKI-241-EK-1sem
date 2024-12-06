#include "Accident.h"

Accident::Accident(const std::string& date, const std::string& description)
    : date(date), description(description) {}

void Accident::addCar(std::shared_ptr<Car> car) {
    involvedCars.push_back(car);
}

std::string Accident::getInfo() const {
    return "Date: " + date + ", Description: " + description;
}