#include "map.h"

Map::Map()
{

}

/**
 * @brief Adds the provided city to this map.
 * @param Pointer to city to be added
 */
void Map::addCity(City* city)
{
    qDebug() << QString("Add %1 to map.").arg(city->getName());
    cities.push_back(city);
}

/**
 * @brief Adds the provided street to this map. If the cities linked by the street
 *  have not been added to this map before, the street is not added.
 * @param Pointer to the street to be added
 * @return true if the street has beed added.
 */
bool Map::addStreet(Street* street)
{
    City* city1 = street->getCity1();
    City* city2 = street->getCity2();

    bool exist1 = false;
    bool exist2 = false;

    for(City* city : cities)
    {
        if(city == city1)
        {
            exist1 = true;
        }

        if(city == city2)
        {
            exist2 = true;
        }
    }

    if(exist1 && exist2)
    {
        qDebug() << QString("Add street form %1 to %2 to map.").arg(street->getCity1()->getName()).arg(street->getCity2()->getName());
        streets.push_back(street);
        return true;
    }
    else
    {
        qDebug() << QString("Cities missing.");
        return false;
    }
}

/**
 * @brief Search for a city in this map by given name.
 * @param name
 * @return the city pointer, if city not found nullptr
 */
City* Map::findCity(const QString cityName) const
{
    for(City* city : cities)
    {
        if(city->getName() == cityName)
        {
            return city;
        }
    }

    return nullptr;
}

/**
 * @brief Search for streets in this map.
 * @param city where you want the street_list from
 * @return A list of all streets in this map connected to provided city.
 */
QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> out;

    for(Street* street : streets)
    {
        if(street->getCity1() == city || street->getCity2() == city)
        {
            out.push_back(street);
        }
    }

    return out;
}

/**
 * @brief Look for opposite city.
 * @param street
 * @param city
 * @return Opposite city of the street. If city has no connection to street returns nullptr.
 */
City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if(street->getCity1() == city || street->getCity2() == city)
    {
        if(street->getCity1() == city)
        {
            return street->getCity2();
        }
        return street->getCity1();
    }
    return 0;
}

/**
 * @brief Calculate the street length.
 * @param street
 * @return Length of the street
 */
double Map::getLength(const Street* street) const
{
    double x = abs(street->getCity1()->getX() - street->getCity2()->getX());
    double y = abs(street->getCity1()->getY() - street->getCity2()->getY());
    return std::sqrt(x*x+y*y);
}

/**
 * @brief Draws all cities and streets onto a scene.
 * @param scene
 */
void Map::draw(QGraphicsScene& scene)
{
    for(City* city : cities)
    {
        city->draw(scene);
    }
    for(Street* street : streets)
    {
        street->draw(scene);
    }
}
