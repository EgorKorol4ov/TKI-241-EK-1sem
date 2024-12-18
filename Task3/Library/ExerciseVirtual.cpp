#include "../Library/ExerciseVirtual.h"
#include <iostream>

namespace miit::matrix::exercises
{
    ExerciseVirtual::ExerciseVirtual(
        const int rows,
        const int columns,
        std::unique_ptr<miit::algebra::Generator> generator,
        std::ostream& out)
        : out(out)
    {
        matrix = std::make_unique<miit::algebra::Matrix>(rows, columns, *generator);
    }

    ExerciseVirtual::~ExerciseVirtual() = default;

    void ExerciseVirtual::Run()
    {
        out << "=== " << title() << " ===" << std::endl;

        out << ":" << std::endl;
        out << *matrix << std::endl;

        out << "Task 1:" << std::endl;
        Task1();

        out << "Task 2:" << std::endl;
        Task2();
    }
}