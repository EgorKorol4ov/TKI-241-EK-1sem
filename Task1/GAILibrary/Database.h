#include <vector>
#include <memory>
#include <string>
#include "Car.h"
#include "Owner.h"
#include "Accident.h"
#include "StolenCarsRegistry.h"

class Database {
private:
    std::vector<std::shared_ptr<Car>> cars;
    std::vector<std::shared_ptr<Owner>> owners;
    std::vector<std::shared_ptr<Accident>> accidents;
    StolenCarsRegistry stolenCarsRegistry;

public:
    void addCar(const std::shared_ptr<Car>& car);
    void addOwner(const std::shared_ptr<Owner>& owner);
    void addAccident(const std::shared_ptr<Accident>& accident);

    void markCarAsStolen(const std::shared_ptr<Car>& car);
    void unmarkCarAsStolen(const std::string& plate);

    std::shared_ptr<Car> findCarByPlate(const std::string& plate) const;
    std::shared_ptr<Owner> findOwnerByCar(const std::string& plate) const;
    std::shared_ptr<Car> findCarByEngineNumber(const std::string& engineNumber) const;

    std::vector<std::shared_ptr<Car>> getStolenCars() const;
    std::map<std::string, int> getMostStolenBrands() const;
};
