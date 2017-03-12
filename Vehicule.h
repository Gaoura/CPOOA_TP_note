#pragma once
#include <string>
#include <vector>

#include "InterventionException.h"
#include "Intervention.h"

class Vehicule
{
private:
	std::string numeroImmatriculation;
	int kilometrage;
    std::vector<Intervention*> carnetEntretien;

	// interdiction de changer le num d'immatriculation une fois la voiture creee
	void setNumeroImmatriculation(const std::string &num)
	{
		numeroImmatriculation = num;
	}

public:

	Vehicule(const std::string &num, int km = 0)
	{
		setNumeroImmatriculation(num);
		setKilometrage(km);
	}

	void setKilometrage(int km)
	{
		if (km < 0)
			throw InterventionException("Kilometrage negatif");
		kilometrage = km;
	}

    const std::vector<Intervention*> & getCarnetEntretien() const
	{
		return carnetEntretien;
	}

	const Intervention* operator[] (int n) const
	{
		return carnetEntretien[n];
	}

	void add(Intervention * i)
	{
		carnetEntretien.push_back(i);
	}

	void remove(int n)
	{
		carnetEntretien.erase(carnetEntretien.begin() + n);
	}

	void afficherCarnetEntretien(std::ostream &s)
    {
        double ct = 0.;

        s << "Carnet d'entretien" << std::endl;
        s << "------------------" << std::endl;

        for (int i(0); i < carnetEntretien.size(); ++i)
        {
            s << (*carnetEntretien[i]) << std::endl;
            ct += carnetEntretien[i]->getMontant();
        }

        s << "------------------" << std::endl;
        s << "Cout total : " << std::to_string(ct) << std::endl;
        s << "------------------" << std::endl;
    }


	operator std::string() const
	{
		return "[immatriculation=" + numeroImmatriculation
                    + ";kilometrage=" + std::to_string(kilometrage) + "]";
	}

    friend std::ostream & operator<< (std::ostream &, const Vehicule &);
};

extern std::ostream & operator<< (std::ostream &, const Vehicule &);
