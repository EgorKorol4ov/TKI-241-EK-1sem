#pragma once
#include "Car.h"
#include <string>
#include <chrono>
#include <memory>

class Car; 

class Accident final : public std::enable_shared_from_this<Accident>
{
private:
    std::chrono::system_clock::time_point date;
    std::string description;
    std::shared_ptr<Car> car; 

    Accident(const std::chrono::system_clock::time_point& date, const std::string& description);

public:
    std::string getInfo() const;
    std::string dateToString() const;
    void setDateFromString(const std::string& dateStr);

    void setCar(const std::shared_ptr<Car>& car); 
};