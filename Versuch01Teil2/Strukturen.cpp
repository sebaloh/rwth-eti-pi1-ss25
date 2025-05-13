/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	struct Person {
		std::string sNachname;
		std::string sVorname;
		int iGerburtsjahr;
		int iAlter;
	};

	Person nBenutzer;
	Person nKopieEinzeln;
	Person nKopieGesamt;

	std::cout << "Nachname: ";
	std::cin >> nBenutzer.sNachname;

	std::cout << "Vorname: ";
	std::cin >> nBenutzer.sVorname;

	std::cout << "Geburtsjahr: ";
	std::cin >> nBenutzer.iGerburtsjahr;

	std::cout << "Alter: ";
	std::cin >> nBenutzer.iAlter;

	std::cout << "---- nBenutzer ----" << std::endl;

	std::cout << "Nachname: " << nBenutzer.sNachname << std::endl;
	std::cout << "Vorname: " << nBenutzer.sVorname << std::endl;
	std::cout << "Geburtsjahr (Alter): " << nBenutzer.iGerburtsjahr << " (" << nBenutzer.iAlter << ")" << std::endl;

	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iGerburtsjahr = nBenutzer.iGerburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;
	nKopieGesamt = nBenutzer;

	std::cout << "---- nKopieEinzeln ----" << std::endl;

	std::cout << "Nachname: " << nKopieEinzeln.sNachname << std::endl;
	std::cout << "Vorname: " << nKopieEinzeln.sVorname << std::endl;
	std::cout << "Geburtsjahr (Alter): " << nKopieEinzeln.iGerburtsjahr << " (" << nKopieEinzeln.iAlter << ")" << std::endl;

	std::cout << "---- nKopieGesamt ----" << std::endl;

	std::cout << "Nachname: " << nKopieGesamt.sNachname << std::endl;
	std::cout << "Vorname: " << nKopieGesamt.sVorname << std::endl;
	std::cout << "Geburtsjahr (Alter): " << nKopieGesamt.iGerburtsjahr << " (" << nKopieGesamt.iAlter << ")" << std::endl;

    return 0;
}
