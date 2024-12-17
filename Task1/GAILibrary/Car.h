#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Owner.h"
#include "Accident.h"

class Car final {
public:
    std::string plateNumber;
    std::string brand;
    std::string model;
    std::string color;
    std::string engineNumber;

    std::shared_ptr<Owner> currentOwner;

    std::vector<Accident> accidents; 

    Car(const std::string& plate, const std::string& brand, const std::string& model,
        const std::string& color, const std::string& engine,
        const std::shared_ptr<Owner>& owner);

    void addAccident(const std::string& description); 
    std::string getAccidentsInfo() const;            
    std::string getInfo() const;
};