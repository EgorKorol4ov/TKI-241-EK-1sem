#pragma once
#include <list>
#include <string>
#include <memory>
#include <algorithm>
#include <map>
#include "Car.h"
#include "Owner.h"

class Database final : public std::enable_shared_from_this<Database>
{
    private:
        std::vector<std::shared_ptr<Car>> cars;
        std::vector<std::shared_ptr<Owner>> owners;

    public:
        void addCar(const std::shared_ptr<Car>& car);
        void addOwner(const std::shared_ptr<Owner>& owner);

        std::shared_ptr<Car> findCarByPlate(const std::string& plate) const;
        std::shared_ptr<Owner> findOwnerByCar(const std::string& plate) const;

        void removeCar(const std::string& plate);
        void removeOwner(const std::string& name);

        std::string getCarsInfo() const;
        std::string getOwnersInfo() const;
};