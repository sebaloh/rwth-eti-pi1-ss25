#ifndef MAP_H
#define MAP_H

#include <QVector>
#include "abstractmap.h"

class Map : public AbstractMap
{
public:
    Map();
    void addCity(City* city) override;
    void draw(QGraphicsScene& scene);
private:
    QVector<City*> cities;
};

#endif // MAP_H
