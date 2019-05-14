#include "layer.h"

layer::layer( ann::data net, unsigned i )
{
    if( 0 == i )
    {
        for( int j = 0; j < net.layers[i].size; j++ )
        {
            neuron.push_back( perceptron( net.inputSize, net.learningRate, net.layers[i].f, net.layers[i].df ) );
        }
    }
    else
    {
        for( int j = 0; j < net.layers[i].size; j++ )
        {
            neuron.push_back( perceptron( net.layers[i-1].size, net.learningRate, net.layers[i].f, net.layers[i].df ) );
        }
    }
}

void layer::calculate( std::vector <double> x, std::vector <double> &out )
{
    out.clear();

	for( unsigned i = 0; i < neuron.size(); i++ )
    {
        out.push_back( neuron[i].calculate( x ) );
    }
}

void layer::propagate( std::vector <double> d, std::vector <double> &sum )
{
	sum.clear();

	for( unsigned i = 0; i < neuron[0].weight.size(); i++ )
    {
		sum.push_back(0);
    }

	for( unsigned i = 0; i < neuron.size(); i++ )
    {
        neuron[i].error( d[i] , sum );
    }

}

void layer::update( std::vector <double> x, std::vector <double> &out )
{
	out.clear();

	for( unsigned i = 0; i < neuron.size(); i++ )
    {
        out.push_back( neuron[i].update( x ) );
    }

}
