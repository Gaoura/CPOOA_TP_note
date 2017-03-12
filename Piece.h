#pragma once
#include <string>

#include "InterventionException.h"

class Piece
{
private:
	std::string reference;
	double prix;
	int tempsRemplacement;

	// une reference ne peut pas etre vide, ni modifiee apres construction de la Piece
	void setReference(const std::string &ref)
	{
		if (ref.empty())
			throw InterventionException("Reference vide");
		reference = ref;
	}

	// pas la peine de tenter de copier une piece
	const Piece & operator= (const Piece&)
	{
		return (*this);
	}

public:
	Piece(const std::string &ref, double p, int temps)
	{
		setReference(ref);
		setPrix(p);
		setTempsRemplacement(temps);
	}

	const std::string & getReference() const
	{
		return reference;
	}

	double getPrix() const
	{
		return prix;
	}

	int getTempsRemplacement() const
	{
		return tempsRemplacement;
	}

	void setPrix(double p)
	{
		if (p < 0.)
			throw InterventionException("Prix negatif");
		prix = p;
	}

	void setTempsRemplacement(int temps)
	{
		if ((temps < 15) || (temps > 360))
			throw InterventionException("Temps de remplacement > 360 ou < 15 minutes");
		tempsRemplacement = temps;
	}

	operator std::string() const
	{
		return "[reference=" + reference + ", prix=" + std::to_string(prix)
                    + ", tempsRemplacement=" + std::to_string(tempsRemplacement) + "]";
	}

	friend bool operator== (const Piece &, const Piece &);
    friend std::ostream & operator<< (std::ostream &, const Piece &);
};

extern bool operator== (const Piece &, const Piece &);
extern std::ostream & operator<< (std::ostream &, const Piece &);
