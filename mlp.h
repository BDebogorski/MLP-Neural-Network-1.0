#ifndef MLP_H__
#define MLP_H__

#include "layer.h"

namespace ann
{
    class mlp
    {
        private:

            std::vector <layer> layers;
            void error( std::vector <double> x, std::vector <double> &d );

        public:

            mlp( data net );
            void calculate( std::vector <double> &x );
            void update( std::vector <double> &x, std::vector <double> d );
    };
}

#endif // MLP_H__
