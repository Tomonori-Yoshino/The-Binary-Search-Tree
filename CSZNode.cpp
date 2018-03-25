#include "CSZNode.h"

/**
 * Overloaded insertion operator for the class of CSZNode.
 *
 * @param[out]   fout  the output stream to which the value is sent
 * @param[out]   n     the value to be displayed
 *
 * @return  the output stream by reference
 */
std::ostream& operator<<( std::ostream& fout, const CSZNode& n )
{
    n.write( fout );
    return fout;
}



