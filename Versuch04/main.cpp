//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

int main()
{
    Vektor erdRadius(0, 6371000, 0);      // bitte sinnvoll initialisieren
    Vektor aussichtsPunkt(0, 6371557.4, 0); // bitte sinnvoll initialisieren
    Vektor sicht(0, 0, 0);
    int count = 0;

    std::cout << std::fixed << std::setprecision(4) << "---- Start ----" << std::endl << "Count: " << count << std::endl << "Winkel: " << erdRadius.winkel(sicht) << std::endl;

    do
    {
    	// eine Stelle mehr möglich, dauert abe deutlich laenger.
    	erdRadius.rotiereUmZ(0.000001 * (M_PI/180));
    	sicht = erdRadius.sub(aussichtsPunkt);
    	count++;
    	std::cout << std::fixed << std::setprecision(4) << "---------------" << std::endl << "Count: " << count << std::endl  << "Winkel: " << erdRadius.winkel(sicht) << std::endl;
    } while (erdRadius.winkel(sicht) >= 90);

    std::cout << std::fixed << std::setprecision(4) << "---------------" << std::endl << std::endl
    		<< "Sie können " << sicht.laenge()/1000 << " Km weit sehen." << std::endl
    		<< "Sie sind " << aussichtsPunkt.laenge() << " Meter hoch." << std::endl
			<< "Der Winkel beträgt " << erdRadius.winkel(sicht) << " Grad." << std::endl
			<< "Anzahl Schritte: " << count << std::endl;

    return 0;
}
