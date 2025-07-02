/*
 * Buch.cpp
 *
 *  Created on: 30.06.2025
 *      Author: sebastian
 */

#include "Buch.h"

Buch::Buch(std::string initTitel, std::string initAutor) : Medium(initTitel)
{
	this->autor = initAutor;
}

Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}

void Buch::ausgabe() const
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

	std::cout << "Autor: " << autor << std::endl;
}
