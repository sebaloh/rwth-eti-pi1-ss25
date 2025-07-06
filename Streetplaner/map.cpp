#include "map.h"

Map::Map()
{

}

void Map::addCity(City* city)
{
    qDebug() << QString("Add %1 to map.").arg(city->getName());
    cities.push_back(city);
}

void Map::draw(QGraphicsScene& scene)
{
    for(City* city : cities)
    {
        city->draw(scene);
    }
}
