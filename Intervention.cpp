#include "Intervention.h"

std::ostream & operator<< (std::ostream &s, const Intervention &o)
{
    return o.print(s);
}
