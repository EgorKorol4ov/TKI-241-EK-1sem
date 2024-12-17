#pragma once
#include "ExerciseVirtual.h"
#include "../Library/Matrix.h"

class MyExercise : public miit::matrix::exercises::ExerciseVirtual
{
public:

    MyExercise(
        const int rows,
        const int columns,
        std::unique_ptr<miit::algebra::Generator> generator,
        std::ostream& out = std::cout)
        : ExerciseVirtual(rows, columns, std::move(generator), out) {}

protected:
    std::string title() const noexcept override;

    void Task1() override;

    void Task2() override;
};