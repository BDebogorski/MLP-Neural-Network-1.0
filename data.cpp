#include "data.h"

void ann::data::addLayer( function f, derivative df, int size )
{
    layers.push_back( layer( f, df, size ) );
}

ann::data::layer::layer( function f, derivative df, int size )
{
    this -> f = f;
    this -> df = df;
    this -> size = size;
}
