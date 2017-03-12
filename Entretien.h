#pragma once
#include "Intervention.h"
#include "InterventionException.h"

class Entretien : public Intervention
{
private:
	int type;
	double forfait;

	static const int NOMBRE_ENTRETIENS = 3;

public:
	static const int Vidange = 1;
	static const int Revision = 2;
	static const int Plaquettes = 3;

	Entretien(const Date& d, int t, double f) : Intervention(d)
	{
		setType(t);
		setForfait(f);
	}

	Entretien(const Entretien& e) : Intervention(e.date)
	{
		setType(e.type);
		setForfait(e.forfait);
	}

	int getType() const
	{
		return type;
	}

	double getForfait() const
	{
		return forfait;
	}

	void setType(int t)
	{
		if ((t < 1) || (t > NOMBRE_ENTRETIENS))
			throw InterventionException("Type inconnu");
		type = t;
	}

	void setForfait(double f)
	{
		// ON VA PAS DONNER DE L'ARGENT APRES AVOIR BOSSE NAMEHO
		if (f < 0.)
			throw InterventionException("Forfait negatif");
		forfait = f;
	}

	double getMontant() const
	{
		return forfait;
	}

	Intervention* clone() const
	{
		return new Entretien(*this);
	}

	operator std::string() const
	{
        return "[date=" + std::string(date)
                    + ", type = " + std::to_string(type)
                    + ", forfait = " + std::to_string(forfait) + "]";
	}

    std::ostream & print(std::ostream &s) const
    {
        return s << "Entretien " << std::string(*this);
    }
};
