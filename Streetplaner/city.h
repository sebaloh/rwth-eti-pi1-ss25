#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class City
{
public:
	/**
	 * @brief Constructor
	 * @param name
	 * @param x-coordinate
	 * @param y-coordinate
	 */
    City(QString name, int x, int y);
    /**
	 * @brief Draws a city onto a scene.
	 * @param scene
	 */
    void draw(QGraphicsScene& scene);
    /**
	 * @brief Return name of city.
	 * @return name
	 */
    QString getName();
    /**
	 * @brief Return x-coordinate of city.
	 * @return x-coordinate
	 */
    int getX();
    /**
	 * @brief Return y-coordinate of city.
	 * @return y-coordinate
	 */
    int getY();
private:
    QString name;
    int x;
    int y;
};

#endif // CITY_H
