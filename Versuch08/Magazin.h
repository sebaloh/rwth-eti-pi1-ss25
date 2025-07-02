/*
 * Magazin.h
 *
 *  Created on: 30.06.2025
 *      Author: sebastian
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"
#include <string>

/*! \brief Magazin-Klasse basierend auf Medium
*
* Diese Klasse stellt ein Magazin dar.
*/
class Magazin : public Medium
{
public:
	/*!
	 * @brief Konstruktor
	 *
	 * Konstruktor der Klasse Magazin
	 *
	 * \param std::string initTitel: Titel des Magazins
	 * \param Datum initDatumAusgabe: Ausgabe des Magazins
	 * \param std::string initSparte: Sparte des Magazins
	 */
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	/*!
	 * @brief virtueller Destruktor
	 */
	virtual ~Magazin();
	/*!
	 * @brief Ausgabefunktion
	 *
	 * Funktion gibt alle Informationen eines Magazins auf der Konsole aus
	 */
	void ausgabe() const override;
	/*!
	 * @brief Ausleihen-Funktion
	 *
	 * \param Person person: Person die das Medium ausleihen m�chte
	 * \param Datum ausleihdatum: Datum an dem das Medium ausgeliehen wird
	 *
	 * \return bool: true,  wenn die Ausleihbeschr�nkungen erf�llt sind und das Medium ausgeliehen werden kann
	 *               false, wenn die Ausleihbeschr�nkungen nicht erf�llt sind und das Medium nicht ausgeliehen werden kann oder es sich um die aktuelle Ausgabe handelt
	 */
	bool ausleihen(Person person, Datum ausleihdatum) override;
private:
	/*!
	 * @brief Ausgabe des Magazins
	 */
	Datum datumAusgabe;
	/*!
	 * @brief Sparte des Magazins
	 */
	std::string sparte;
};

#endif /* MAGAZIN_H_ */
