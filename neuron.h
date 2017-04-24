#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include "const.h"

class Neuron
{
public:
    Neuron();

    Neuron(char d);
    std::vector<std::vector<int> > pic; // образец для каждой буквы
    char symbol;
private:


};

#endif // NEURON_H
