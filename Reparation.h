#include <vector>
#include <math.h>

#include "Intervention.h"
#include "Piece.h"

class Reparation : public Intervention
{
private:
	std::string descriptifPanne;
	std::vector<Piece*> listePieces;

public:
	Reparation(const Date &d, const std::string &panne) : Intervention(d), descriptifPanne(panne), listePieces(0) {}

	// le constructeur par recopie ne recopie pas les Piece
	Reparation(const Reparation& r) : Intervention(r.date), descriptifPanne(r.descriptifPanne), listePieces(0) {}

	const std::string & getDescriptifPanne() const
	{
		return descriptifPanne;
	}

	const std::vector<Piece*> & getListePieces() const
	{
		return listePieces;
	}

	const Piece* operator[] (int n) const
	{
		return listePieces[n];
	}

	void add(Piece * p)
	{
		listePieces.push_back(p);
	}

	void remove(int n)
	{
		listePieces.erase(listePieces.begin() + n);
	}

	int getDuree() const
	{
		int res = 0;
		for (int i(0); i < listePieces.size(); ++i)			res += listePieces[i]->getTempsRemplacement();		return res;
	}

	double getMontant() const
	{
		double res = 0.;

		for (int i(0); i < listePieces.size(); ++i)			res += listePieces[i]->getPrix();

		return res + (ceil(getDuree() / 60.) * 150);
	}

	Intervention * clone() const
	{
		Reparation * r = new Reparation(*this);

        for (int i(0); i < listePieces.size(); ++i)
            r->add(listePieces[i]);

        return r;
	}

	operator std::string() const
	{
		return "[date=" + std::string(date) + ";descriptif=" + descriptifPanne
                    + ";montant=" + std::to_string(getMontant())
                    + ";duree=" + std::to_string(getDuree()) + "]";
	}

    std::ostream & print(std::ostream &s) const
    {
        return s << "Reparation " << std::string(*this);
    }
};
