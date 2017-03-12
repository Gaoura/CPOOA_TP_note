#include "Vehicule.h"

std::ostream & operator<< (std::ostream &s, const Vehicule &o)
{
    return s << "Vehicule " << std::string(o);
}
