/**
 * Praktikum Informatik 1 MMXXV
 *
 * @file test.cpp
 *
 * Stellt Funktionen zum Testen der Spielfunktionen zur Verfuegung
 */


#include <iostream>
#include "config.h"
#include "test.h"


/*
 * Deklaration der in den Tests verwendeten Funktionen.
 * Dadurch weiss der Compiler, das es sich bei den Namen
 * um Funktionsaufrufe handelt, die in einer anderen Datei
 * definiert sind (extern).
 */
extern void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X]);
extern int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X]);
extern bool aufSpielfeld(const int posX, const int posY);
extern bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X],  const int player, const int posX, const int posY);
extern void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int player, const int posX, const int posY);
extern int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int player);


/**
 * @brief Funktion zum Testen der gewinner() Funktion.
 *
 * @param eingabefeld Das zu testende Spielfeld.
 * @param richtig Der erwartete Gewinner.
 * @param testNummer Nummer des laufenden Tests
 * @return True wenn der berechnete Gewinner und der erwartete Gewinner uebereinstimmen. False ansonsten.
 */
bool gewinnerTest(const int eingabefeld[GROESSE_Y][GROESSE_X], const int richtig, const int testNummer)
{
    std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'gewinner()' aus ..." << std::endl;
    std::cout << "----------------------------------" << std::endl << std::endl;
    int ergebnis = gewinner(eingabefeld);
    if (ergebnis == richtig)
    {
        std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;
        if (AUSFUEHRLICH == 1)
        {
            zeigeSpielfeld(eingabefeld);
            std::cout << std::endl << "Berechnetes Ergebnis: " << ergebnis << std::endl << "Richtiges Ergebnis: " << richtig
                      << std::endl << std::endl;
        }
        return false;
    }
}


/**
 * @brief Funktion zum Testen der aufSpielfeld() Funktion
 *
 * @param posX Index Spalte
 * @param posY Index Zeile
 * @param richtig Das erwartete Ergebnis
 * @param testNummer Nummer des laufenden Tests
 * @return True wenn Test bestanden, ansonsten false
 */
bool aufSpielfeldTest(const int posX, const int posY, const bool richtig, const int testNummer)
{
	std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'aufSpielfeld()' aus ..." << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;
	bool ergebnis = aufSpielfeld(posX, posY);
	if (ergebnis == richtig)
	{
		std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
		return true;
	}
	else
	{
		std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;
		if (AUSFUEHRLICH == 1)
		{
			std::cout << std::endl << "Berechnetes Ergebnis: " << ergebnis << std::endl << "Richtiges Ergebnis: " << richtig
					  << std::endl << std::endl;
		}
		return false;
	}
}

/**
 * @brief Funktion zum Testen der zugGueltig() Funktion
 *
 * @param eingabeFeld Das aktuelle Spielfeld
 * @param spieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @param richtig Das erwartete Ergebnis
 * @param testNummer Nummer des laufenden Tests
 * @return True wenn Test bestanden, ansonsten false
 */
bool zugGueltigTest(const int eingabeFeld[GROESSE_Y][GROESSE_X], const int spieler, const int posX,
                     const int posY, const bool richtig, const int testNummer)
{
	std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'zugGueltig()' aus ..." << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;
	bool ergebnis = zugGueltig(eingabeFeld, spieler, posX, posY);
	if (ergebnis == richtig)
	{
		std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
		return true;
	}
	else
	{
		std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;
		if (AUSFUEHRLICH == 1)
		{
			std::cout << std::endl << "Berechnetes Ergebnis: " << ergebnis << std::endl << "Richtiges Ergebnis: " << richtig
					  << std::endl << std::endl;
		}
		return false;
	}
}

/**
 * @brief Funktion zum Testen der zugAusfuehren() Funktion
 *
 * @param eingabeFeld Das aktuelle Spielfeld
 * @param ergebnisFeld Das Spielfeld nach dem Zug
 * @param spieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 * @param testNummer NUmmer des laufenden Tests
 * @return True wenn Test bestanden, ansonsten false
 */
bool zugAusfuehrenTest(int eingabeFeld[GROESSE_Y][GROESSE_X], const int ergebnisFeld[GROESSE_Y][GROESSE_X],
                       const int spieler, const int posX, const int posY, const int testNummer)
{
	std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'zugAusfuehren()' aus ..." << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;
	zugAusfuehren(eingabeFeld, spieler, posX, posY);
	for (int j = 0; j < GROESSE_Y; j++)
	{
		for (int i = 0; i < GROESSE_X; i++)
		{
			if (eingabeFeld[j][i] != ergebnisFeld[j][i])
			{
				std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;
				if (AUSFUEHRLICH == 1)
				{
					std::cout << "eingabeFeld" << std::endl;
					zeigeSpielfeld(eingabeFeld);
					std::cout << "ergebnisFeld" << std::endl;
					zeigeSpielfeld(ergebnisFeld);
				}
				return false;
			}
		}
	}
	std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
	return true;
}

/**
 * @brief Funktion zum Testen der moeglicheZuege() Funktion
 *
 * @param eingabeFeld Das aktuelle Spielfeld
 * @param spieler Der aktuelle Spieler
 * @param richtig Das erwartete Ergebnis
 * @param testNummer NUmmer des laufenden Tests
 * @return True wenn Test bestanden, ansonsten false
 */
bool moeglicheZuegeTest(const int eingabeFeld[GROESSE_Y][GROESSE_X], const int spieler,
                         const int richtig, const int testNummer)
{
	std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'moeglicheZuege()' aus ..." << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;
    int ergebnis = moeglicheZuege(eingabeFeld, spieler);
    if (ergebnis == richtig)
    {
    	std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
		return true;
    }
    std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;
    return false;
}

/**
 * @brief Funktion, die alle Tests ausfuehrt
 *
 * @return True, wenn alle Tests bestanden wurden, ansonsten false
 */
bool ganzenTestAusfuehren()
{
    bool gesamtErgebnis = true;

// Jeder Test steht in einem eigenen Block {}, damit es keine Namenskonflikte gibt
// z.B. eingabeFeld oder korrektesErgebnis

// ---------- TESTE GEWINNER ---------- //
    {
        int eingabeFeld[3][8][8] = {
            {   {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2}
            },

            {   {1, 1, 2, 1, 1, 2, 1, 1},
                {2, 1, 1, 2, 1, 1, 2, 1},
                {1, 2, 1, 1, 2, 1, 1, 2},
                {1, 1, 2, 1, 1, 2, 1, 1},
                {2, 1, 1, 2, 1, 1, 2, 1},
                {1, 2, 1, 1, 2, 1, 1, 2},
                {1, 1, 2, 1, 1, 2, 1, 1},
                {2, 1, 1, 2, 1, 1, 2, 1}
            },

            {   {1, 2, 2, 1, 2, 2, 1, 2},
                {2, 1, 2, 2, 1, 2, 2, 1},
                {2, 2, 1, 2, 2, 1, 2, 2},
                {1, 2, 2, 1, 2, 2, 1, 2},
                {2, 1, 2, 2, 1, 2, 2, 1},
                {2, 2, 1, 2, 2, 1, 2, 2},
                {1, 2, 2, 1, 2, 2, 1, 2},
                {2, 1, 2, 2, 1, 2, 2, 1}
            }
        };

        int korrektesErgebnis[3] = {0, 1, 2};

        for (int i = 0; i < 3; i++)
        {
            bool tmp_ergebnis = gewinnerTest(eingabeFeld[i], korrektesErgebnis[i], i);
            if (gesamtErgebnis == true && tmp_ergebnis == false)
            {
                gesamtErgebnis = false;
            }
        }

        std::cout << "Ende des Tests fuer 'gewinner()'" << std::endl << std::endl;
    }

// ---------- TESTE POSITION IM FELD---------- //
    {
        int position[6][2] = { {2, 3}, {0, 8}, {-1, 7}, {2, -1}, {8, 5}, {-1,8} };   // posX, posY
        bool korrektesErgebnis[6] = {true, false, false, false, false, false};

        for (int i = 0; i < 6; i++)
        {
            bool tmp_ergebnis = aufSpielfeldTest(position[i][0], position[i][1], korrektesErgebnis[i], i);
            if (gesamtErgebnis == true && tmp_ergebnis == false)
            {
				gesamtErgebnis = false;
			}
        }

        std::cout << "Ende des Test fuer 'aufSpielfeld()'" << std::endl << std::endl;
    }
    
// ---------- TESTE ZUG GUELTIG ---------- //
    {
        int eingabeFeld[7][8][8] = {
                {   {1, 0, 2, 0, 0, 1, 1, 1},
                    {0, 0, 2, 0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0, 1, 2, 2},
                    {2, 2, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 2, 0},
                    {0, 0, 0, 2, 1, 1, 0, 2},
                    {1, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 0, 1}
                },

                {   {1, 0, 2, 0, 0, 1, 1, 1},
                    {0, 0, 2, 0, 0, 1, 0, 0},
                    {0, 0, 2, 0, 0, 2, 1, 1},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 2, 0},
                    {0, 0, 0, 2, 1, 1, 0, 2},
                    {1, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 0, 1}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 1, 0, 0, 2, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 0},
                    {2, 0, 1, 2, 0, 2, 0, 0},
                    {0, 2, 0, 2, 2, 2, 2, 2},
                    {0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 2, 2, 2},
                    {0, 2, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 1, 1, 1, 0, 0}
                },

                {   {2, 1, 0, 0, 2, 1, 1, 1},
                    {0, 2, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 2, 0, 0, 0, 1},
                    {0, 1, 1, 1, 0, 1, 0, 0},
                    {1, 0, 0, 1, 1, 0, 0, 2},
                    {0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 1, 0, 0, 0, 0, 2, 0},
                    {1, 1, 2, 0, 0, 2, 2, 1}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {
                    {1, 2, 2, 2, 2, 2, 2, 2},
                    {1, 2, 1, 1, 2, 2, 2, 2},
                    {1, 1, 1, 2, 2, 2, 2, 2},
                    {1, 1, 1, 2, 2, 2, 2, 2},
                    {1, 1, 1, 1, 2, 2, 2, 2},
                    {1, 1, 1, 0, 2, 2, 2, 2},
                    {1, 0, 0, 0, 2, 0, 0, 2},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                }
            };

        int spieler[7] = {1, 2, 2, 1, 2, 1,1};
        int position[7][2] = { {2, 3}, {0, 3}, {4, 3}, {3, 4}, {3, 5}, {3, 4}, {5, 7} };  // posX, posY
        bool korrektesErgebnis[7] = {false, false, false, true, true, false, false};

        for (int i = 0; i < 7; i++)
        {
            bool tmp_ergebnis = zugGueltigTest(eingabeFeld[i], spieler[i], position[i][0], position[i][1], korrektesErgebnis[i], i);
            if (gesamtErgebnis == true && tmp_ergebnis == false)
			{
				gesamtErgebnis = false;
			}
        }

        std::cout << "Ende des Test fuer 'zugGueltig()'" << std::endl << std::endl;
    }


// ---------- TESTE ZUG AUSFUEHREN ---------- //
    {
        int eingabeFeld[10][8][8] = {
                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 2, 2},
                    {2, 2, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 1, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 0},
                    {0, 0, 0, 2, 0, 2, 0, 0},
                    {0, 0, 0, 2, 2, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 1, 0},
                    {0, 0, 0, 2, 0, 2, 0, 0},
                    {0, 0, 0, 2, 2, 0, 0, 0},
                    {0, 1, 2, 0, 2, 2, 1, 0},
                    {0, 0, 0, 2, 2, 0, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 1, 1, 1, 1, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 2, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 2, 1},
                    {1, 0, 1, 1, 2, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 1, 0, 1},
                    {0, 0, 0, 0, 0, 2, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 2, 2, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 2, 0, 0, 2, 0, 0},
                    {0, 1, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                }
            };

        int ergebnisFeld[10][8][8] {
                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 2, 2},
                    {2, 2, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 1, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 0},
                    {0, 0, 0, 2, 0, 1, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0, 1, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 1, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 1, 1, 1, 1, 1, 1, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 0, 0},
                    {0, 0, 0, 0, 2, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 2, 1, 1, 1, 1, 0},
                    {0, 0, 2, 0, 0, 0, 0, 0},
                    {0, 0, 2, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 2, 1},
                    {1, 2, 2, 2, 2, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },
                {   {0, 0, 0, 0, 0, 1, 0, 1},
                    {0, 0, 0, 0, 0, 1, 1, 0},
                    {0, 0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 1, 1, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 2, 0, 0, 2, 0, 0},
                    {0, 1, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                }
            };

        int spieler[10]={0,0,0,1,2,0,1,2,2,1};
        int position[10][2]=                       // eine andere, moegliche Darstellung
                    {                              // der gegebenen Positionen posX, posY
                        {0,0},
                        {0,0},
                        {0,0},
                        {3,4},
                        {3,5},
                        {0,0},
                        {3,4},
                        {2,4},
                        {1,4},
                        {5,2}
                    };

        for (int i = 0; i < 10; i++)
        {
            bool tmp_ergebnis = zugAusfuehrenTest(eingabeFeld[i], ergebnisFeld[i], spieler[i], position[i][0], position[i][1], i);
            if (gesamtErgebnis == true && tmp_ergebnis == false)
            {
				gesamtErgebnis = false;
			}
        }
    }


// ---------- TESTE MOEGLICHE ZUEGE ---------- //
    {
        int eingabeFeld[2][8][8] {
                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 2, 0, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 2, 1, 1, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                }
            };

        int spieler[2] = {1, 1};
        int korrektesErgebnis[2] = {4, 5};

        for (int i = 0; i < 2; i++)
        {
            bool tmp_ergebnis = moeglicheZuegeTest(eingabeFeld[i], spieler[i], korrektesErgebnis[i], i);
            if (gesamtErgebnis == true && tmp_ergebnis == false)
			{
				gesamtErgebnis = false;
			}
        }
    }

    return gesamtErgebnis;
}
