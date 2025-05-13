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
    std::string sNachname;
    
    // Hier folgt Ihr eigener Code
    
    std::cout << "Vorname: " << std::endl;
    std::cin >> sVorname;
    std::cout << "Nachname: " << std::endl;
    std::cin >> sNachname;

    std::string sVornameNachname = sVorname + " " + sNachname;
    std::string sNachnameVorname = sNachname + ", " + sVorname;

    std::cout << "Vorname Nachname: " << sVornameNachname << std::endl;
    std::cout << "Nachname, Vorname: " << sNachnameVorname << std::endl;

    return 0;
}
