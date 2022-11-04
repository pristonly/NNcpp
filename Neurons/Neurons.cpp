#include "ITeach.h"

#include <iostream>
#include <fstream>

int main()
{
    FORWARD_DISTURB layers;
    layers.AddNewLayer(2);
    layers.AddNewLayer(2);
    layers.AddNewLayer(2);
    layers.AddNewLayer(1);
    layers.InitWeights();
    double* input = layers.InputLayer();
    for (size_t i = 0; i < 2; ++i)
    {
        input[i] = 1.0;
    }
    layers.Run();
    std::ifstream file("input.txt");
    std::ifstream fileans("answer.txt");
    DataSet MySet(file, fileans);
    TEACHER teach(MySet);
    std::cout << "Hello World!\n";
    return 0;
}