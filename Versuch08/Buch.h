/*
 * Buch.h
 *
 *  Created on: 30.06.2025
 *      Author: sebastian
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"
#include <string>

/*! \brief Buch-Klasse basierend auf Medium
*
* Diese Buch stellt ein Magazin dar.
*/
class Buch : public Medium
{
public:
	/*!
	 * @brief Konstruktor
	 *
	 * Konstruktor der Klasse Buch
	 *
	 * \param std::string initTitel: Titel des Buches
	 * \param std::string initAutor: Autor des Buches
	 */
	Buch(std::string initTitel, std::string initAutor);
	/*!
	 * @brief virtueller Destruktor
	 */
	virtual ~Buch();
	/*!
	 * @brief Ausgabefunktion
	 *
	 * Funktion gibt alle Informationen eines Buces auf der Konsole aus
	 */
	void ausgabe() const override;
private:
	/*!
	 * @brief Der Autor des Buches
	 */
	std::string autor;
};

#endif /* BUCH_H_ */
