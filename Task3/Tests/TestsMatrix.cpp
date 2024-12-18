#include "CppUnitTest.h"
#include "../Library/Matrix.h"
#include "../Library/Generator.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace MatrixTests
{
    TEST_CLASS(MatrixTests)
    {
    public:

        TEST_METHOD(Constructor_ValidDimensions_Success)
        {
            // Arrange
            int rows = 3, cols = 4;

            // Act
            Matrix matrix(rows, cols);

            // Assert
            Assert::AreEqual(matrix.getRows(), rows);
            Assert::AreEqual(matrix.getCols(), cols);
        }

        TEST_METHOD(Constructor_InvalidDimensions_Throws)
        {
            // Arrange
            int rows = -3, cols = -4;

            // Act & Assert
            Assert::ExpectException<std::invalid_argument>([&]()
                {
                    Matrix matrix(rows, cols);
                });
        }

        TEST_METHOD(Fill_ValidGenerator_FillsMatrix)
        {
            // Arrange
            int rows = 2, cols = 2;
            Matrix matrix(rows, cols);

            // Create a mock generator (returns 42 every time)
            class MockGenerator : public Generator
            {
                int generate() override { return 42; }
            } mockGenerator;

            // Act
            matrix.fill(mockGenerator);

            // Assert
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    Assert::AreEqual(matrix[i][j], 42);
                }
            }
        }

        TEST_METHOD(OperatorIndex_ValidIndex_ReturnsRow)
        {
            // Arrange
            int rows = 2, cols = 3;
            Matrix matrix(rows, cols);

            // Act
            matrix[0][0] = 10;
            matrix[1][2] = 20;

            // Assert
            Assert::AreEqual(matrix[0][0], 10);
            Assert::AreEqual(matrix[1][2], 20);
        }

        TEST_METHOD(OperatorIndex_InvalidIndex_Throws)
        {
            // Arrange
            int rows = 2, cols = 2;
            Matrix matrix(rows, cols);

            // Act & Assert
            Assert::ExpectException<std::out_of_range>([&]()
                {
                    matrix[3][0] = 10; 
                });
        }

        TEST_METHOD(CopyConstructor_ValidMatrix_CopiesData)
        {
            // Arrange
            Matrix original(2, 2);
            original[0][0] = 1;
            original[1][1] = 2;

            // Act
            Matrix copy(original);

            // Assert
            Assert::AreEqual(copy[0][0], 1);
            Assert::AreEqual(copy[1][1], 2);
            Assert::AreEqual(copy.getRows(), original.getRows());
            Assert::AreEqual(copy.getCols(), original.getCols());
        }

        TEST_METHOD(MoveConstructor_ValidMatrix_MovesData)
        {
            // Arrange
            Matrix original(2, 2);
            original[0][0] = 1;
            original[1][1] = 2;

            // Act
            Matrix moved(std::move(original));

            // Assert
            Assert::AreEqual(moved[0][0], 1);
            Assert::AreEqual(moved[1][1], 2);
            Assert::AreEqual(moved.getRows(), 2);
            Assert::AreEqual(moved.getCols(), 2);
            Assert::AreEqual(original.getRows(), 0);
            Assert::AreEqual(original.getCols(), 0);
        }

        TEST_METHOD(ToString_ValidMatrix_ReturnsString)
        {
            // Arrange
            Matrix matrix(2, 2);
            matrix[0][0] = 1;
            matrix[0][1] = 2;
            matrix[1][0] = 3;
            matrix[1][1] = 4;

            // Act
            std::string result = matrix.toString();

            // Assert
            std::string expected = "1 2 \n3 4 \n";
            Assert::AreEqual(result, expected);
        }

        TEST_METHOD(StreamOperator_ValidMatrix_PrintsToStream)
        {
            // Arrange
            Matrix matrix(2, 2);
            matrix[0][0] = 1;
            matrix[0][1] = 2;
            matrix[1][0] = 3;
            matrix[1][1] = 4;

            std::ostringstream oss;

            // Act
            oss << matrix;

            // Assert
            std::string expected = "1 2 \n3 4 \n";
            Assert::AreEqual(oss.str(), expected);
        }
    };
}