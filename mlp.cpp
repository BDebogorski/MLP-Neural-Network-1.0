#include "mlp.h"

ann::mlp::mlp( data net )
{
	for( unsigned i = 0; i < net.layers.size(); i++ )
    {
		layers.push_back( layer( net, i ) );
	}
}

void ann::mlp::calculate( std::vector <double> &x )
{
	for( unsigned i = 0; i < layers.size(); i++ )
    {
		layers[i].calculate( x, x );
    }
}

void ann::mlp::error( std::vector <double> x, std::vector <double> &d )
{
	calculate( x );

	for( unsigned i = 0; i < x.size(); i++ )
		d[i] -= x[i];
}

void ann::mlp::update( std::vector <double> &x, std::vector <double> d )
{
	error( x, d );

	for( int i = layers.size() - 1; i >= 0; i-- )
    {
		layers[i].propagate( d, d );
    }

	for( unsigned i = 0; i < layers.size(); i++ )
    {
		layers[i].update( x, x );
    }
}
