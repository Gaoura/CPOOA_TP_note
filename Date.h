#pragma once

#include <string>
#include <iostream>

class Date
{
	long long _jour, _mois, _annee;

public:

	enum { janvier = 1, fevrier, mars, avril, mai, juin, juillet, aout, septembre, octobre, novembre, decembre };

	Date(int jour, int mois, int annee) :
		_jour(jour),
		_mois(mois),
		_annee(annee)
	{
	}

	virtual ~Date() { 	}

	int getJour() const {
		return _jour;
	}

	int getMois() const {
		return _mois;
	}

	int getAnnee() const {
		return _annee;
	}

	operator std::string() const {
		return "" + std::to_string(_jour) + "/" + std::to_string(_mois) + "/" + std::to_string(_annee);
	}
};

inline std::ostream & operator << (std::ostream & s, const Date& op) {
	s << (std::string)op;
	return s;
}