//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, back);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        back = neuesElement;
    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, front, nullptr);

    if (back == nullptr)                                       // Liste leer?
    {
        back = neuesElement;
        front = neuesElement;
    }
    else
    {
        front->setPrev(neuesElement);
        front = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Entfernen eines Listenelements am Ende der Liste.
 *
 * @return void
 */
void Liste::popBack()
{
    ListenElement* cursor = back;

    if (back == front)                                       // Liste enth�lt nur ein Listenelement
    {
        delete back;                                         // Listenelement l�schen
        back = nullptr;
        front = nullptr;
    }
    else
    {
        back = back->getPrev();
        back->setNext(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Gibt die Daten des letzten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataBack()
{
    return back->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
    delete cursor;
}

/**
 * @brief Ausgabe der Liste vom letzen bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
	ListenElement* cursor = back;

	while (cursor != nullptr)
	{
		cursor->getData().ausgabe();
		cursor = cursor->getPrev();
	}
	delete cursor;
}

/**
 * @brief Löschen eines Elements nach der Matrikelnummer
 *
 * @return void
 */
void Liste::deleteElement(unsigned int matNr)
{
	ListenElement* cursor = front;
	int number = 1;

	while (cursor != nullptr)
	{
		if (cursor->getData().getMatNr() == matNr)
		{
			cursor->getPrev()->setNext(cursor->getNext());
			cursor->getNext()->setPrev(cursor->getPrev());
			break;
		}

		for (int i = 0; i < number; i++)
		{
			cursor = cursor->getNext();
		}
	}
	delete cursor;
}
