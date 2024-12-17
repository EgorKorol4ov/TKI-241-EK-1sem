#pragma once
#include "../Library/Generator.h"
#include <vector>
#include <iostream>
#include <string>

namespace miit::algebra
{

    class Matrix
    {
    private:
        
        std::vector<std::vector<int>> data;
  
        int rows;

        int cols;

    public:
        
        Matrix(int rows, int cols);

        Matrix(const Matrix& other);

        Matrix(Matrix&& other) noexcept;

        ~Matrix() = default;

        Matrix& operator=(const Matrix& other);

        Matrix& operator=(Matrix&& other) noexcept;

        std::vector<int>& operator[](int index);

        const std::vector<int>& operator[](int index) const;

        int getRows() const;

        int getCols() const;

        void fill(Generator& generator);

        std::string toString() const;

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

        Matrix(int rows, int cols, Generator& generator);
    };
}