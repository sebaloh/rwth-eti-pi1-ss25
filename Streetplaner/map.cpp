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
