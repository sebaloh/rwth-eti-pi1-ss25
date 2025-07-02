/*
 * DVD.h
 *
 *  Created on: 30.06.2025
 *      Author: sebastian
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"
#include <string>

/*! \brief DVD-Klasse basierend auf Medium
*
* Diese Klasse stellt ein DVD dar.
*/
class DVD : public Medium
{
public:
	/*!
	 * @brief Konstruktor
	 *
	 * Konstruktor der Klasse DVD
	 *
	 * \param std::string initTitel: Titel der DVD
	 * \param int initAltersfreigabe: Altersfreigabe der DVD
	 * \param std::string initGenre: Genre der DVD
	 */
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	/*!
	 * @brief virtueller Destruktor
	 */
	virtual ~DVD();
	/*!
	 * @brief Ausgabefunktion
	 *
	 * Funktion gibt alle Informationen eines Mediums auf der Konsole aus
	 */
	void ausgabe() const override;
	/*!
	 * @brief Ausleihen-Funktion
	 *
	 * \param Person person: Person die die DVD ausleihen m�chte
	 * \param Datum ausleihdatum: Datum an dem die DVD ausgeliehen wird
	 *
	 * \return bool: true,  wenn die Ausleihbeschr�nkungen erf�llt sind und die DVD ausgeliehen werden kann
	 *               false, wenn die Ausleihbeschr�nkungen nicht erf�llt sind und die DVD nicht ausgeliehen werden kann oder die Alterfreigabe nicht erreicht wird
	 */
	bool ausleihen(Person person, Datum ausleihdatum) override;
private:
	/*!
	 * @brief Altersfreigabe der DVD
	 */
	int altersfreigabe;
	/*!
	 * @brief Genere der DVD
	 */
	std::string genre;
};

#endif /* DVD_H_ */
