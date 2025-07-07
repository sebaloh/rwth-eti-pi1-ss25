#ifndef STREET_H
#define STREET_H

#include <QGraphicsScene>
#include "city.h"

class Street
{
public:
    Street(City* city1, City* city2);
    void draw(QGraphicsScene& scene);
    void drawRed(QGraphicsScene& scene);
    City* getCity1() const;
    City* getCity2() const;
private:
    City* city1;
    City* city2;
};

#endif // STREET_H
