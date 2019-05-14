#include "mlp.h"
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

double f( double x )
{
    return 1 / ( 1 + exp(-x) );
}

double df( double x )
{
    return exp(-x) / pow( exp(-x) + 1, 2 );
}

void learning( ann::mlp &network, int n )
{

    int a;
    int b;

    std::vector <double> x;
    std::vector <double> d;

    for( int i= 0; i < n; i++ )
    {

        a = rand() % 2;
        b = rand() % 2;

        x.push_back(a);
        x.push_back(b);
        d.push_back( a ^ b );

        network.update(x, d);

        x.clear();
        d.clear();
    }
}

void test( ann::mlp &network )
{

    int a;
    int b;

    std::vector <double> x;
    std::vector <double> d;

    do
    {
        std::cin >> a;
        std::cin >> b;

        x.push_back(a);
        x.push_back(b);

        network.calculate(x);

        std::cout << x[0] << std::endl;

        x.clear();
    }
    while( a < 2 && b < 2 );
}

int main()
{
    srand( time( NULL ) );

    ann::data netData;
    netData.inputSize = 2;
    netData.learningRate = 0.9;

    netData.addLayer( f, df, 2 );
    netData.addLayer( f, df, 1 );

    ann::mlp network( netData );

    learning( network, 100000 );
    test( network );
}
