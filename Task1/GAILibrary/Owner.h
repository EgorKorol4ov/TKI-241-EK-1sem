#pragma once
#include <string>
#include <vector>
#include "Car.h"

class Owner final : public std::enable_shared_from_this<Owner>
{
private:
    std::string name;
    std::string address;
    std::string phone;

    std::vector<Car*> cars; 

    Owner(const std::string& name, const std::string& address, const std::string& phone);

public:
    void addCar(std::shared_ptr<Car>& car);
    std::string getInfo() const;
};