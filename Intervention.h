#pragma once
#include "Date.h"

class Intervention
{
protected:
	Date date;

	// on ne modifiera pas la date une fois creee donc pas de setDate

public:
	Intervention(const Date &d) : date(d) {}

	const Date & getDate() const
	{
		return date;
	}

	virtual double getMontant() const = 0;
	virtual Intervention* clone() const = 0;
	virtual operator std::string() const = 0;
    virtual std::ostream & print(std::ostream &s) const = 0;

    friend std::ostream & operator<< (std::ostream &, const Intervention &);
};

extern std::ostream & operator<< (std::ostream &, const Intervention &);
