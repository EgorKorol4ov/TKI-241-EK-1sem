#pragma once
#include <string>
#include <vector>
#include <memory>

class Owner; 

class Car {
public:
    std::string plateNumber;
    std::string brand;
    std::string model;
    std::string color;
    std::string engineNumber;
    std::vector<std::string> accidents;

    std::weak_ptr<Owner> currentOwner;

    Car(const std::string& plate, const std::string& brand, const std::string& model,
        const std::string& color, const std::string& engine);

    void addAccident(const std::string& accident);
    std::string getInfo() const;
};
