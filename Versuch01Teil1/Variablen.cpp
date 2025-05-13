//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	std::string sVorname;
	int iName1;
	int iName2;
	int iPosition1;
	int iPosition2;

	std::cout << "Vorname: " << std::endl;
	std::cin >> sVorname;

	iName1 = sVorname[0];
	iName2 = sVorname[1];

	// A = 65, a = 97 -> diff = 32
	iPosition1 = (iName1 - 64) % 32;
	iPosition2 = (iName2 - 64) % 32;

	std::cout << "Position erster Buchstabe im Alphabet: " << iPosition1 << std::endl;
	std::cout << "Position zweiter Buchstabe im Alphabet: " << iPosition2 << std::endl;
    
    return 0;
}
