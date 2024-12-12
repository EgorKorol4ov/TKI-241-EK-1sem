#pragma once
#include <string>
#include <memory>
#include "Owner.h"
#include "Accident.h"

class Car final:public std::enable_shared_from_this<Car> 
{
    public:
        std::string plateNumber;
        std::string brand;
        std::string model;
        std::string color;
        std::string engineNumber;

        std::weak_ptr<Owner> currentOwner;

        Car(const std::string& plate, const std::string& brand, const std::string& model,
            const std::string& color, const std::string& engine);

        void addAccident(const std::string& accident);
        void removeCar(const std::shared_ptr<Car>& car);
        std::string getInfo() const;
};