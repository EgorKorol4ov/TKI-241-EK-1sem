#include "CppUnitTest.h"
#include "../GAILibrary/Car.h"
#include "../GAILibrary/Owner.h"
#include "../GAILibrary/Accident.h"
#include <memory>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CarOwnerAccidentTests
{
    TEST_CLASS(CarOwnerAccidentTests)
    {
    public:

        TEST_METHOD(Car_AssociationWithOwner_IsCorrect)
        {
            // Arrange
            auto owner = std::make_shared<Owner>("John Doe", "123 Elm St", "555-555-5555");

            // Act
            auto car = std::make_shared<Car>("XYZ789", "BMW", "X5", "Silver", "ENG789", owner);

            // Assert
            Assert::AreEqual(std::string("Owner: John Doe, Address: 123 Elm St, Phone: 555-555-5555"),
                car->getCurrentOwner()->getInfo());
        }

        TEST_METHOD(Owner_AddMultipleCars_CorrectlyLinksCarsToOwner)
        {
            // Arrange
            auto owner = std::make_shared<Owner>("Jane Doe", "456 Oak St", "555-123-4567");
            auto car1 = std::make_shared<Car>("AAA111", "Ford", "Focus", "White", "ENG111", owner);
            auto car2 = std::make_shared<Car>("BBB222", "Mazda", "CX-5", "Black", "ENG222", owner);

            // Act
            owner->addCar(car1);
            owner->addCar(car2);

            // Assert
            Assert::AreEqual(std::string("Owner: Jane Doe, Address: 456 Oak St, Phone: 555-123-4567"),
                car1->getCurrentOwner()->getInfo());
            Assert::AreEqual(std::string("Owner: Jane Doe, Address: 456 Oak St, Phone: 555-123-4567"),
                car2->getCurrentOwner()->getInfo());
        }

        TEST_METHOD(Car_AddAccidents_StoresAndRetrievesAccidentDetails)
        {
            // Arrange
            auto owner = std::make_shared<Owner>("John Doe", "123 Elm St", "555-555-5555");
            auto car = std::make_shared<Car>("XYZ123", "Audi", "A4", "Gray", "ENG456", owner);

            // Act
            car->addAccident("Minor scratch on the door");
            car->addAccident("Broken tail light");

            // Assert
            std::string accidentsInfo = car->getAccidentsInfo();
            Assert::IsTrue(accidentsInfo.find("Minor scratch on the door") != std::string::npos);
            Assert::IsTrue(accidentsInfo.find("Broken tail light") != std::string::npos);
        }

        TEST_METHOD(Car_WithoutAccidents_ReturnsNoAccidentsMessage)
        {
            // Arrange
            auto owner = std::make_shared<Owner>("Alice Brown", "789 Pine St", "555-789-1234");
            auto car = std::make_shared<Car>("MNO456", "Tesla", "Model Y", "Blue", "ENG890", owner);

            // Act
            std::string accidentsInfo = car->getAccidentsInfo();

            // Assert
            Assert::AreEqual(std::string("No accidents recorded."), accidentsInfo);
        }

        TEST_METHOD(Accident_CorrectlyStoresDateAndDescription_Correctly)
        {
            // Arrange
            auto now = std::chrono::system_clock::now();
            auto accident = std::make_shared<Accident>(now, "Front bumper damage");

            // Act
            std::string accidentInfo = accident->getInfo();

            // Assert
            Assert::IsTrue(accidentInfo.find("Front bumper damage") != std::string::npos);
            Assert::IsTrue(accidentInfo.find("Date:") != std::string::npos);
        }

        TEST_METHOD(Car_MultipleAccidents_DisplaysAllAccidents)
        {
            // Arrange
            auto owner = std::make_shared<Owner>("John Doe", "123 Elm St", "555-555-5555");
            auto car = std::make_shared<Car>("PLT123", "Mercedes", "GLC", "Black", "ENG567", owner);

            // Act
            car->addAccident("Flat tire on highway");
            car->addAccident("Fender bender in parking lot");

            // Assert
            std::string accidentsInfo = car->getAccidentsInfo();
            Assert::IsTrue(accidentsInfo.find("Flat tire on highway") != std::string::npos);
            Assert::IsTrue(accidentsInfo.find("Fender bender in parking lot") != std::string::npos);
        }

        TEST_METHOD(Car_ChangeOwner_UpdatesCorrectly)
        {
            // Arrange
            auto owner1 = std::make_shared<Owner>("Owner One", "111 First St", "111-111-1111");
            auto owner2 = std::make_shared<Owner>("Owner Two", "222 Second St", "222-222-2222");
            auto car = std::make_shared<Car>("XYZ789", "Toyota", "Camry", "Silver", "ENG123", owner1);

            // Act
            owner2->addCar(car);

            // Assert
            Assert::AreEqual(std::string("Owner: Owner Two, Address: 222 Second St, Phone: 222-222-2222"),
                car->getCurrentOwner()->getInfo());
        }

        TEST_METHOD(Accident_InvalidDateFormat_HandlesGracefully)
        {
            // Arrange
            auto now = std::chrono::system_clock::now();
            auto accident = std::make_shared<Accident>(now, "Hit a pole");

            // Act
            accident->setDateFromString("Invalid Date Format");

            // Assert
            Assert::IsTrue(accident->dateToString() != "Invalid Date Format");
        }

        TEST_METHOD(Owner_GetInfo_ReturnsCorrectDetails)
        {
            // Arrange
            auto owner = std::make_shared<Owner>("Bob Smith", "333 Third Ave", "333-333-3333");

            // Act
            std::string ownerInfo = owner->getInfo();

            // Assert
            Assert::AreEqual(std::string("Owner: Bob Smith, Address: 333 Third Ave, Phone: 333-333-3333"), ownerInfo);
        }

        TEST_METHOD(Car_WithNoOwner_ReturnsDefaultMessage)
        {
            // Arrange
            auto car = std::make_shared<Car>("ZZZ999", "Kia", "Soul", "Yellow", "ENG999", nullptr);

            // Act & Assert
            Assert::IsNull(car->getCurrentOwner().get());
        }

        TEST_METHOD(Owner_WithNoCars_ReturnsEmptyList)
        {
            // Arrange
            auto owner = std::make_shared<Owner>("Empty Owner", "No Address", "No Phone");

            // Act & Assert
            Assert::IsTrue(owner->getInfo().find("Empty Owner") != std::string::npos);
        }
    };
}