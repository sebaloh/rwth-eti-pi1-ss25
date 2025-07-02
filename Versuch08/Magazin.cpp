/*
 * Magazin.cpp
 *
 *  Created on: 30.06.2025
 *      Author: sebastian
 */

#include "Magazin.h"

#include <time.h>

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte) : Medium(initTitel)
{
	this->datumAusgabe = initDatumAusgabe;
	this->sparte = initSparte;
}

Magazin::~Magazin()
{
	// TODO Auto-generated destructor stub
}

void Magazin::ausgabe() const
{
	std::cout << "ID: " << ID << std::endl;
	std::cout << "Titel: " << titel << std::endl;

	if (status)
	{
		std::cout << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
	}
	else
	{
		std::cout << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
	}

	std::cout << "Ausgabe: " << datumAusgabe << std::endl;
	std::cout << "Sparte: " << sparte << std::endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
	Datum aktuellesDatum;
	if (aktuellesDatum.operator -(datumAusgabe) < 1)
	{
		std::cout << "Dies ist die neuste Ausgabe und darf nicht verliehen werden." << std::endl;
		return false;
	}
	else
	{
		return Medium::ausleihen(person, ausleihdatum);
	}
}
