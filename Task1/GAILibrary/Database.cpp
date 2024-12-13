#include "Database.h"

Database::Database(const std::vector<std::shared_ptr<Car>>& cars, const std::vector<std::shared_ptr<Owner>>& owners)
    : cars(cars), owners(owners) {}

void Database::addCar(const std::shared_ptr<Car>& car) 
{
    cars.push_back(car);
}

void Database::addOwner(const std::shared_ptr<Owner>& owner) 
{
    owners.push_back(owner);
}

std::shared_ptr<Car> Database::findCarByPlate(const std::string& plate) const 
{
    auto it = std::find_if(cars.begin(), cars.end(), [&plate](const std::shared_ptr<Car>& car) 
        {
            return car->plateNumber == plate;
        });
    return (it != cars.end()) ? *it : nullptr;
}

std::shared_ptr<Owner> Database::findOwnerByCar(const std::string& plate) const 
{
    auto car = findCarByPlate(plate);
    if (car && !car->currentOwner.expired()) 
    {
        return car->currentOwner.lock(); 
    }
    return nullptr;
}

void Database::removeCar(const std::string& plate) 
{
    auto it = std::find_if(cars.begin(), cars.end(), [&plate](const std::shared_ptr<Car>& car) 
        {
            return car->plateNumber == plate;
        });
    if (it != cars.end()) 
    {
        if (!(*it)->currentOwner.expired()) 
        {
            (*it)->currentOwner.lock()->removeCar(*it); 
        }
        cars.erase(it); 
    }
}

void Database::removeOwner(const std::string& name) 
{
    auto it = std::find_if(owners.begin(), owners.end(), [&name](const std::shared_ptr<Owner>& owner) 
        {
            return owner->name == name;
        });
    if (it != owners.end()) {
        for (auto& car : (*it)->cars) 
        {
            if (auto carPtr = car.lock()) 
            {
                carPtr->currentOwner.reset(); 
            }
        }
        owners.erase(it); 
    }
}

std::string Database::getCarsInfo() const 
{
    std::string info;
    for (const auto& car : cars) 
    {
        info += car->getInfo() + "\n";
    }
    return info;
}

std::string Database::getOwnersInfo() const 
{
    std::string info;
    for (const auto& owner : owners) 
    {
        info += owner->getInfo() + "\n";
    }
    return info;
}