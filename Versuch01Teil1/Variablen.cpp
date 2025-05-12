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
    int iErste = 0;
    int iZweite = 0;
    
    // Hier folgt Ihr eigener Code
    
    std::cout << "1. Ganzzahl eingeben: " << std::endl;
    std::cin >> iErste;
    std::cout << "2. Ganzzahl eingeben: " << std::endl;
    std::cin >> iZweite;

    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite;

    std::cout << "Summe: " << iSumme << std::endl;
    std::cout << "Division: " << iQuotient << std::endl;

    return 0;
}
