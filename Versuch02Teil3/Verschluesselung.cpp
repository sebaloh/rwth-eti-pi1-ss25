///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	for (int i = 0; i < (int) wort.length(); ++i) {
		wort[i] = schluessel[1][wort[i] - 65];
	}

	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	for (int i = 0; i < (int) wort.length(); ++i) {
		wort[i] = schluessel[0][wort[i] - 65];
	}

	return wort;
}

int main()
{
	char lookup[2][26] = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
						{'Z', 'X', 'O', 'R', 'K', 'U', 'B', 'M', 'V', 'P', 'H', 'C', 'Y', 'N', 'E', 'S', 'W', 'A', 'Q', 'G', 'T', 'L', 'I', 'F', 'D', 'J'} };

	string wort;

	std::cout << "Wort: ";
	std::cin >> wort;

	string verschluesselt = verschluesseln(lookup, wort);

	std::cout << "Verschlüsselt: " << verschluesselt << std::endl;
	std::cout << "Entschlüsselt: " << entschluesseln(lookup, wort) << std::endl;


	return 0;
}
