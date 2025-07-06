#ifndef MAP_H
#define MAP_H

#include <QVector>
#include "abstractmap.h"

class Map : public AbstractMap
{
public:
    Map();
    void addCity(City* city) override;
    bool addStreet(Street* street) override;
    void draw(QGraphicsScene& scene);
private:
    QVector<City*> cities;
    QVector<Street*> streets;
};

#endif // MAP_H
