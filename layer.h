#ifndef LAYER_H__
#define LAYER_H__

#include "perceptron.h"
#include "data.h"

class layer
{
    private:

        std::vector <perceptron> neuron;

    public:

        layer( ann::data net, unsigned i );
        void calculate( std::vector <double> x, std::vector <double> &out );
        void propagate( std::vector <double> d, std::vector <double> &sum );
        void update( std::vector <double> x, std::vector <double> &out );
};

#endif // LAYER_H__
