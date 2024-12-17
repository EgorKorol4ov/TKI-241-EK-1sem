#pragma once
#include <string>
#include <vector>
#include "Car.h"

class Owner 
{
public:
    std::string name;
    std::string address;
    std::string phone;

    std::vector<Car*> cars; 

    Owner(const std::string& name, const std::string& address, const std::string& phone);

    void addCar(Car* car); 
    std::string getInfo() const;
};