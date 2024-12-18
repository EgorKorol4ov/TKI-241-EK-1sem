#include "../Library/MyExercise.h"
#include <iostream>
#include <cmath> 

std::string MyExercise::title() const noexcept
{
    return "My Exercise";
}

void MyExercise::Task1()
{
    out << "Выполнение задачи 1:" << std::endl;

    for (size_t j = 0; j < matrix->getCols(); ++j) 
    {
        int min_elem = (*matrix)[0][j]; 
        int min_row = 0;

        for (size_t i = 1; i < matrix->getRows(); ++i) 
        {
            if ((*matrix)[i][j] < min_elem)
            {
                min_elem = (*matrix)[i][j];
                min_row = i;
            }
        }

        (*matrix)[min_row][j] = 0; 
    }

    out << *matrix << std::endl;
}

void MyExercise::Task2()
{
    out << "Выполнение задачи 2:" << std::endl;

    std::vector<int> last_row = (*matrix)[matrix->getRows() - 1];

    std::vector<std::vector<int>> new_matrix;

    for (size_t i = 0; i < matrix->getRows(); ++i)
    {
        new_matrix.push_back((*matrix)[i]); 

        int max_abs_elem = std::abs((*matrix)[i][0]);
        for (size_t j = 1; j < matrix->getCols(); ++j)
        {
            if (std::abs((*matrix)[i][j]) > max_abs_elem)
            {
                max_abs_elem = std::abs((*matrix)[i][j]);
            }
        }

        for (size_t j = 0; j < matrix->getCols(); ++j)
        {
            if (std::abs((*matrix)[i][j]) == max_abs_elem)
            {
                new_matrix.push_back(last_row); 
                break; 
            }
        }
    }

    *matrix = new_matrix;

    out << *matrix << \n;
}