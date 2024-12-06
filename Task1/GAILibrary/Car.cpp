#include "Car.h"

Car::Car(const std::string& plate, const std::string& brand, const std::string& model,
    const std::string& color, const std::string& engine)
    : plateNumber(plate), brand(brand), model(model), color(color), engineNumber(engine) {}

void Car::addAccident(const std::string& accident) {
    accidents.push_back(accident);
}

std::string Car::getInfo() const {
    return "Plate: " + plateNumber + ", Brand: " + brand + ", Model: " + model +
        ", Color: " + color + ", Engine: " + engineNumber;
}