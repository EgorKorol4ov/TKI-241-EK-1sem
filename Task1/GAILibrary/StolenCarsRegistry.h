#include <vector>
#include <memory>
#include <string>
#include <map>
#include "Car.h"

class StolenCarsRegistry {
private:
    std::vector<std::shared_ptr<Car>> stolenCars;

public:
    void addCar(const std::shared_ptr<Car>& car);
    void removeCar(const std::string& plate);
    std::vector<std::shared_ptr<Car>> getStolenCars() const;
    std::map<std::string, int> getMostStolenBrands() const;
};