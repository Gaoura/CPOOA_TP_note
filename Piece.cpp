#include "Piece.h"

inline bool operator== (const Piece &pg, const Piece &pd)
{
	return (pg.reference == pd.reference) && (pg.prix == pd.prix) && (pg.tempsRemplacement == pd.tempsRemplacement);
}

std::ostream & operator<< (std::ostream &s, const Piece &op)
{
	return s << "Piece " << std::string(op);
}
