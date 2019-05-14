#ifndef DATA_H
#define DATA_H

#include "perceptron.h"

namespace ann
{
    struct data
    {
        struct layer
        {
            function f;
            derivative df;
            int size;

            layer( function f, derivative df, int size );
        };

        int inputSize;
        double learningRate;

        std::vector <layer> layers;

        void addLayer( function f, derivative df, int size );
    };
}

#endif // DATA_H
