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

    std::cout << "Vorname: " << std::endl;
    std::cin >> sVorname;

    iName1 = sVorname[0];
    iName2 = sVorname[1];

    std::cout << "Erster Buchstab: " << iName1 << std::endl;
    std::cout << "Zweiter Buchstabe: " << iName2 << std::endl;
    
    return 0;
}
