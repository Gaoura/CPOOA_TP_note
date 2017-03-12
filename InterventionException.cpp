#include <iostream>
#include "InterventionException.h"

/**
Fonction de surcharge pour l'affichage <<
*/
std::ostream & operator << (std::ostream &s, const InterventionException &e)
{
	return s << e._msg;
}

