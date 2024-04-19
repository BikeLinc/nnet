// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "mlp.h"

int main()
{
    std::vector<Layer> layers = {
        Layer(2, activations::identity, activations::identityP),
        Layer(2, activations::unitStep, activations::unitStepP),
        Layer(2, activations::identity, activations::identityP)
    };

    MLP mlp(layers);
}
