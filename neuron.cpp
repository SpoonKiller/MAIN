#include "neuron.h"

Neuron::Neuron()
{
    pic.resize(45, std::vector<int> (45, 255));
}

Neuron::Neuron(char d)
{
    pic.resize(45, std::vector<int> (45, 255));
    symbol = d;
}
