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
    int spielfeld[2][3];
    int iZweite = 1;

	spielfeld[0][0] = 1;
	spielfeld[0][1] = 2;
	spielfeld[0][2] = 3;

	spielfeld[1][0] = 4;
	spielfeld[1][1] = 5;
	spielfeld[1][2] = 6;

	std::cout << spielfeld[0][0] << " " << spielfeld[0][1] << " " << spielfeld[0][2] << std::endl;
	std::cout << spielfeld[1][0] << " " << spielfeld[1][1] << " " << spielfeld[1][2] << std::endl;
    
    std::cout << iZweite << std::endl;
    
    return 0;
}
