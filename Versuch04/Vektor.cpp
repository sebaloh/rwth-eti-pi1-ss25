//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Function subtracting two vectors
 */
Vektor Vektor::sub(const Vektor& input) const
{
	Vektor result(this->x - input.x, this->y - input.y, this->z - input.z);
	return result;
}

/**
 * @brief Function returning the length of the vector
 */
double Vektor::laenge() const
{
	return sqrt(x*x + y*y + z*z);
}

/**
 * @brief Function returning the scalar product of two vectors
 */
double Vektor::skalarProd(const Vektor& input) const
{
	return (this->x*input.x + this->y*input.y + this->z*input.z);
}

/**
 * @brief Function returning the angle between two vectors
 */
double Vektor::winkel(const Vektor& input) const
{
	return acos(this->skalarProd(input) / (this->laenge()*input.laenge())) * (180/M_PI);
}

/**
 * @brief Function that rotates the vector
 */
void Vektor::rotiereUmZ(const double rad)
{
	this->x = this->x * cos(rad) - this->y * sin(rad);
	this->y = this->x * sin(rad) + this->y * cos(rad);
}
