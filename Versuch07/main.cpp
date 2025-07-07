/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Student.h"

int main()
{
    Student student;
    std::ifstream eingabe;
    std::ofstream ausgabe;
    std::vector<Student> studentenListe;
    std::vector<Student>::iterator it;;
    std::vector<Student>::reverse_iterator revIt;
    char abfrage;

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement hinten entfernen" << std::endl
                  << "(3): Datenelement hinzufügen" << std::endl
                  << "(4): Datenelement löschen" << std::endl
                  << "(5): Datenbank vorwärts ausgeben" << std::endl
                  << "(6): Datenbank rückwärts ausgeben" << std::endl
                  << "(7): Datenelement vorne löschen" << std::endl
                  << "(8): Daten aus einer Datei einlesen" << std::endl
                  << "(9): Daten in eine Datei sichern" << std::endl
				  << "(a): Sortieren nach MatNr" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');
        std::cout << std::endl;

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
            	{
            		unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";

					std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
					getline(std::cin, name);

					std::cout << "Geburtsdatum: ";
					getline(std::cin, geburtstag);

					std::cout << "Adresse: ";
					getline(std::cin, adresse);

					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;
					std::cin.ignore(10, '\n');

					student = Student(matNr, name, geburtstag, adresse);

            		studentenListe.push_back(student);
            	}
                break;

            // Datenelement hinten entfernen
            case '2':
            	{
            		studentenListe.pop_back();
            	}
                break;

            // Datenelement an Index hinzufügen
            case '3':
				{
					unsigned int index = 1;

					std::cout << "Stelle (Start 0): ";
					std::cin >> index;
					std::cin.ignore(10, '\n');

					unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";

					std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
					getline(std::cin, name);

					std::cout << "Geburtsdatum: ";
					getline(std::cin, geburtstag);

					std::cout << "Adresse: ";
					getline(std::cin, adresse);

					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;
					std::cin.ignore(10, '\n');

					student = Student(matNr, name, geburtstag, adresse);

					it = studentenListe.begin() + index;
					studentenListe.insert(it, student);
				}
                break;

            // Datenelement nach MatNr löschen
            case '4':
            	{
            		if (studentenListe.empty()) {
						std::cout << "Die Liste ist leer. Kein Student zum Loeschen vorhanden." << std::endl;
					}

            		unsigned int matNrToFind;
					std::cout << "MatNr: ";
					std::cin >> matNrToFind;

					std::cin.ignore(10, '\n');

					Student student(matNrToFind, "", "", "");

					auto it = std::find(studentenListe.begin(), studentenListe.end(), student);

					if(it != studentenListe.end())
					{
						studentenListe.erase(it);
					}
					else
					{
						std::cout << "Student nicht gefunden." << std::endl;
					}
				}
				break;

			// Datenbank vorwärts ausgeben
            case '5':
            	{
            		for (it = studentenListe.begin(); it != studentenListe.end(); it++)
            		{
            			std::cout << (*it) << std::endl;
            		}
				}
            	break;

			// Datenbank rückwärts ausgeben
			case '6':
				{
					for (revIt = studentenListe.rbegin(); revIt != studentenListe.rend(); revIt++)
					{
						std::cout << (*revIt) << std::endl;
					}
				}
				break;

			// Datenelement vorne hinzufügen
			case '7':
				{
					studentenListe.erase(studentenListe.begin());
				}
				break;

			// Daten aus einer Datei einlesen
			case '8':
				{
					studentenListe.clear();

					std::string filename;

					std::cout << "Dateiname: ";
					std::cin >> filename;
					std::cin.ignore(10, '\n');

					eingabe.open(filename);
					if (!eingabe)
					{
						std::cout << "Fehler beim Öffnen der Datei!" << std::endl;
						break;
					}

					unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";

					eingabe >> matNr;

					while(!eingabe.eof())
					{
						eingabe.ignore(1,'\n');
						std::getline(eingabe, name);
						std::getline(eingabe, geburtstag);
						std::getline(eingabe, adresse);

						student = Student(matNr, name, geburtstag, adresse);

						studentenListe.push_back(student);

						eingabe >> matNr;
					}
				}
				break;

			// Daten in eine Datei sichern
			case '9':
				{
					std::string filename;

					std::cout << "Dateiname: ";
					std::cin >> filename;
					std::cin.ignore(10, '\n');

					ausgabe.open(filename);
					if (!ausgabe)
					{
						std::cout << "Fehler beim Öffnen der Datei!" << std::endl;
						break;
					}

					for (it = studentenListe.begin(); it != studentenListe.end(); it++)
					{
						ausgabe << (*it).getMatNr() << std::endl;
						ausgabe << (*it).getName() << std::endl;
						ausgabe << (*it).getGeburtstag() << std::endl;
						ausgabe << (*it).getAdresse() << std::endl;
					}
				}
				break;

			case 'a':
				{
					if (studentenListe.empty()) {
						std::cout << "Die Liste ist leer. Nichts zu sortieren." << std::endl;
					}

					std::sort(studentenListe.begin(), studentenListe.end());

					std::cout << "\n--- Sortierte Studentenliste ---" << std::endl;
					for (const auto& student : studentenListe) {
						std::cout << student << std::endl;
					}
				}
				break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
