#include "Car.h"
#include "Owner.h"
#include "Accident.h"

Car::Car(const std::string& plate, const std::string& brand, const std::string& model,
    const std::string& color, const std::string& engine,
    const std::shared_ptr<Owner>& owner)
    : plateNumber(plate), brand(brand), model(model), color(color), engineNumber(engine),
    currentOwner(owner) {
    currentOwner->addCar(this);
}

void Car::addAccident(const std::string& description)
{
    auto now = std::chrono::system_clock::now();
    auto accident = std::make_shared<Accident>(now, description);
    accident->setCar(shared_from_this()); 
    accidents.push_back(accident);
}

std::string Car::getAccidentsInfo() const
{
    if (accidents.empty()) return "No accidents recorded.";

    std::ostringstream oss;
    for (const auto& accident : accidents)
    {
        oss << accident->getInfo() << "\n";
    }
    return oss.str();
}

std::string Car::getInfo() const
{
    return "Plate: " + plateNumber + ", Brand: " + brand + ", Model: " + model +
        ", Color: " + color + ", Engine: " + engineNumber;
}

std::shared_ptr<Owner> Car::getCurrentOwner()
{
    return this->currentOwner;
}
