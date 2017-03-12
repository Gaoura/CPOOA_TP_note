#include <iostream>

#include "Piece.h"
#include "Date.h"
#include "Reparation.h"
#include "Entretien.h"
#include "Vehicule.h"

int main() {
	Piece *	p1 = new Piece("Courroie transmission", 130., 25);
	std::cout << "p1 = " << *p1 << std::endl;

	Piece *	p2 = new Piece("Alternateur", 245., 45);
	std::cout << "p2 = " << *p2 << std::endl;

	Piece *	p3;

	try {
		p3 = new Piece("Boite de vitesses", 245., 0);
	}
	catch (InterventionException e) {
		std::cout << e.what() << std::endl;
	}

	Date d1(23, Date::octobre, 2014);
	std::cout << "d1 = " << d1 << std::endl;

	Reparation * r1 = new Reparation(d1, "Pb d'alternateur A4");
	std::cout << "r1 = " << *r1 << std::endl;
	r1->add(p1);
	r1->add(p2);
	std::cout << "r1 = " << *r1 << std::endl;

	Intervention * r2 = r1->clone();
	std::cout << "r2 = " << *r2 << std::endl;

	Entretien *e1 = new Entretien(Date(11, Date::mars, 2015), Entretien::Vidange, 450.);
	std::cout << "e1 = " << *e1 << std::endl;

	Intervention *e2 = e1->clone();
	std::cout << "e2 = " << *e2 << std::endl;

	Vehicule *A4 = new Vehicule("FL309DE", 8234);
	std::cout << "A4 = " << *A4 << std::endl;

	A4->add(e1);
	A4->add(r1);

	A4->afficherCarnetEntretien(std::cout);

	system("pause");
}
