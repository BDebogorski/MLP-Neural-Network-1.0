#include "perceptron.h"
#include <cstdlib>

perceptron::perceptron( int inputSize, double learningRate, function f, derivative df )
{
    this -> f = f;
    this -> df = df;
    this -> learningRate = learningRate;

    for( int i = 0; i < inputSize; i++ )
    {
        weight.push_back( (double) rand() / RAND_MAX );
    }

    bias = (double) rand() / RAND_MAX;
}

double perceptron::calculate( std::vector <double> x )
{
    sum = 0;

    for( unsigned int i = 0; i < x.size(); i++ )
    {
        sum += x[i] * weight[i];
    }
    sum += bias;

    return f( sum );
}

double perceptron::update( std::vector <double> x )
{
	float y = calculate( x );
	float delta = learningRate * gradient * df( sum );

	for( unsigned i = 0; i < weight.size(); i++ )
    {
		weight[i] += delta * x[i];
    }

	bias += delta;

	return y;
}

void perceptron::error( double gradient, std::vector <double> &sum )
{
	this -> gradient = gradient;

	for( unsigned i = 0; i < weight.size(); i++ )
    {
		sum[i] += gradient * weight[i];
    }
}
