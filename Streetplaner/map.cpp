#include "map.h"

Map::Map()
{

}

void Map::addCity(City* city)
{
    qDebug() << QString("Add %1 to map.").arg(city->getName());
    cities.push_back(city);
}

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

double Map::getLength(const Street* street) const
{
    double x = abs(street->getCity1()->getX() - street->getCity2()->getX());
    double y = abs(street->getCity1()->getY() - street->getCity2()->getY());
    return std::sqrt(x*x+y*y);
}

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
