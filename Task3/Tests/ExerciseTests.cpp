#include "CppUnitTest.h"
#include "../Library/Matrix.h"
#include "../Library/Generator.h"
#include "../Library/ExerciseVirtual.h"
#include "../Library/MyExercise.h"
#include <memory>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;
using namespace miit::matrix::exercises;

namespace ExerciseTests
{
    TEST_CLASS(ExerciseTests)
    {
    public:

        TEST_METHOD(Constructor_ExerciseVirtual_Success)
        {
            // Arrange
            int rows = 3, cols = 3;
            class MockGenerator : public Generator
            {
                int generate() override { return 1; }
            } mockGenerator;

            std::ostringstream oss;

            // Act
            ExerciseVirtual* exercise = new MyExercise(rows, cols, std::make_unique<MockGenerator>(), oss);

            // Assert
            Assert::IsNotNull(exercise);
            delete exercise;
        }

        TEST_METHOD(Run_ExerciseVirtual_DisplaysTasksAndMatrix)
        {
            // Arrange
            int rows = 2, cols = 3;

            class MockGenerator : public Generator
            {
                int generate() override { return 1; }
            } mockGenerator;

            std::ostringstream oss;

            MyExercise exercise(rows, cols, std::make_unique<MockGenerator>(), oss);

            // Act
            exercise.Run();

            // Assert
            std::string result = oss.str();
            Assert::IsTrue(result.find("=== My Exercise ===") != std::string::npos);
            Assert::IsTrue(result.find("Task 1:") != std::string::npos);
            Assert::IsTrue(result.find("Task 2:") != std::string::npos);
        }

        TEST_METHOD(Task1_ModifiesMatrix_MinElementInColumnsReplacedWithZero)
        {
            // Arrange
            int rows = 3, cols = 3;

            class MockGenerator : public Generator
            {
                int counter = 1;
                int generate() override { return counter++; }
            } mockGenerator;

            std::ostringstream oss;

            MyExercise exercise(rows, cols, std::make_unique<MockGenerator>(), oss);

            // Act
            exercise.Task1();

            // Assert
            std::string result = oss.str();
            Assert::IsTrue(result.find("0") != std::string::npos); 
        }

        TEST_METHOD(Task2_ModifiesMatrix_AddsLastRowAfterMaxAbsElementRow)
        {
            // Arrange
            int rows = 3, cols = 3;

            class MockGenerator : public Generator
            {
                int counter = -1;
                int generate() override { return counter--; }
            } mockGenerator;

            std::ostringstream oss;

            MyExercise exercise(rows, cols, std::make_unique<MockGenerator>(), oss);

            // Act
            exercise.Task2();

            // Assert
            std::string result = oss.str();
            Assert::IsTrue(result.find("Added rows") != std::string::npos); 
        }
    };
}