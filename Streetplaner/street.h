#ifndef STREET_H
#define STREET_H

#include <QGraphicsScene>
#include "city.h"

class Street
{
public:
	/**
	 * @brief Constructor.
	 * @param start city
	 * @param finish city
	 */
    Street(City* city1, City* city2);
    /**
	 * @brief Draws a green street.
	 * @param scene
	 */
    void draw(QGraphicsScene& scene);
    /**
	 * @brief Draws a red street.
	 * @param scene
	 */
    void drawRed(QGraphicsScene& scene);
    /**
	 * @brief Return first city.
	 * @return city
	 */
    City* getCity1() const;
    /**
	 * @brief Return second city.
	 * @return city
	 */
    City* getCity2() const;
private:
    City* city1;
    City* city2;
};

#endif // STREET_H
