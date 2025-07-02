/*
 * DVD.cpp
 *
 *  Created on: 30.06.2025
 *      Author: sebastian
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) : Medium(initTitel)
{
	this->altersfreigabe = initAltersfreigabe;
	this->genre = initGenre;
}

DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

void DVD::ausgabe() const
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

	std::cout << "FSK: ab " << altersfreigabe << " Jahre" << std::endl;
	std::cout << "Genre: " << genre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	Datum aktuellesDatum;
	if (aktuellesDatum.operator -(person.getGeburtsdatum()) < altersfreigabe * 12)
	{
		std::cout << "Es besteht eine Altersbeschränkung." << std::endl;
		return false;
	}
	else
	{
		return Medium::ausleihen(person, ausleihdatum);
	}
}
