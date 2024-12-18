#include "../Library/Generator.h"
#include "../Library/Matrix.h"
#include <sstream>

namespace miit::algebra
{
    Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {}

    Matrix::Matrix(int rows, int cols, Generator& generator) : rows(rows), cols(cols), data(rows, std::vector<int>(cols))
    {
        fill(generator);
    }

    void Matrix::fill(Generator& generator)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = generator.generate();
            }
        }
    }

    Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}


    Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(std::move(other.data))
    {
        other.rows = 0;
        other.cols = 0;
    }


    Matrix& Matrix::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }


    Matrix& Matrix::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            rows = other.rows;
            cols = other.cols;
            data = std::move(other.data);
            other.rows = 0;
            other.cols = 0;
        }
        return *this;
    }


    std::vector<int>& Matrix::operator[](int index)
    {
        return data[index];
    }

    const std::vector<int>& Matrix::operator[](int index) const
    {
        return data[index];
    }

    int Matrix::getRows() const
    {
        return rows;
    }


    int Matrix::getCols() const
    {
        return cols;
    }

    std::string Matrix::toString() const
    {
        std::ostringstream oss;
        for (const auto& row : data)
        {
            for (const auto& elem : row)
            {
                oss << elem << " ";
            }
            oss << std::endl;
        }
        return oss.str();
    }
    std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        for (int i = 0; i < matrix.rows; ++i)
        {
            for (int j = 0; j < matrix.cols; ++j)
            {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
}