#ifndef PERCEPTRON_H__
#define PERCEPTRON_H__

#include <vector>

typedef double ( *function )( double x );
typedef double ( *derivative )( double x );

class perceptron
{
    private:

        friend class layer;
        std::vector <double> weight;

    protected:

        double sum;
        double bias;
        double gradient;
        double learningRate;

        function f;
        derivative df;

    public:

        perceptron( int inputSieze, double learningRate, function f, derivative df );

        double update( std::vector <double> x );
        double calculate( std::vector <double> x );
        void error( double gradient, std::vector <double> &sum );

};

#endif // PERCEPTRON_H__
