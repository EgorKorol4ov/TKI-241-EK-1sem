#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Car.h"

class Accident {
public:
    std::string date;
    std::string description;
    std::vector<std::shared_ptr<Car>> involvedCars;

    Accident(const std::string& date, const std::string& description);

    void addCar(std::shared_ptr<Car> car);
    std::string getInfo() const;
};
