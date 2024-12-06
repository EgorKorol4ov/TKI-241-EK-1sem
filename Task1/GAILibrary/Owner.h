#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Car.h"

class Owner : public std::enable_shared_from_this<Owner> {
public:
    std::string name;
    std::string address;
    std::string phone;
    std::vector<std::shared_ptr<Car>> cars;

    Owner(const std::string& name, const std::string& address, const std::string& phone);

    void addCar(std::shared_ptr<Car> car);
    void removeCar(const std::shared_ptr<Car>& car);
    std::string getInfo() const;
};