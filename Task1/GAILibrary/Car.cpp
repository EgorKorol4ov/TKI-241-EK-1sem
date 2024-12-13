#include "Car.h"

Car::Car(const std::string& plate, const std::string& brand, const std::string& model,
    const std::string& color, const std::string& engine)
    : plateNumber(plate), brand(brand), model(model), color(color), engineNumber(engine) {}

void Car::addAccident(const std::string& accident) 
{
    Accident push_back(accident);
}

std::string Car::getInfo() const 
{
    return "Plate: " + plateNumber + ", Brand: " + brand + ", Model: " + model +
        ", Color: " + color + ", Engine: " + engineNumber;
}

void Car::removeCar(const std::shared_ptr<Car>& car)
{
    cars.erase(std::remove_if(cars.begin(), cars.end(),
        [&car](const std::weak_ptr<Car>& weakCar)
        {
            return weakCar.lock() == car;
        }), cars.end());

    car->currentOwner.reset();
}