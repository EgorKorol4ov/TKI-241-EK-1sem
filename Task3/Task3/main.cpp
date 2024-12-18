#include "../Library/Matrix.h"
#include "../Library/Generator.h"
#include "../Library/IStreamGenerator.h"
#include "../Library/RandomGenerator.h"
#include "../Library/ExerciseVirtual.h"
#include "../Library/MyExercise.h"
#include <iostream>
#include <locale>

int main()
{
    std::unique_ptr<miit::algebra::Generator> randomGenerator = std::make_unique<miit::algebra::RandomGenerator>(1, 100);

    MyExercise exercise(3, 3, std::move(randomGenerator));

    exercise.Run();

    return 0;
}