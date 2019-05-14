#include "file.h"

ann::netFile::netFile( const char* path )
{
    this -> path = path;
}

bool ann::netFile::save( data net )
{
    std::fstream file;
    file.open( path, std::ios::out );

    if( !file.good() )
    {
        return false;
    }

    file << net.learningRate;
    file << ' ';
    file << net.inputSize;
    file << ' ';
    file << net.layers.size();
    file << ' ';

    for( unsigned i = 0; i < net.layers.size(); i++ )
    {
        file << net.layers[i].size;
        file << ' ';

        for( unsigned j = 0; j < net.layers[i].size; j++ )
        {
            file << ;
            file << ' ';
        }
    }

    file.close();
}

bool ann::netFile::load( data &net )
{
    std::fstream file;
    file.open( path, std::ios::in );

    if( !file.good() )
    {
        return false;
    }

    file.close();
}
