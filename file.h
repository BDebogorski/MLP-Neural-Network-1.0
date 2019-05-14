#ifndef DATA_H__
#define DATA_H__

#include <fstream>
#include "data.h"

namespace ann
{
    class netFile
    {

        private:

            const char* path;

        public:

            netFile( const char* path );

            bool save( data net );
            bool load( data &net );
    };
}

#endif
