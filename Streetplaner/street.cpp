#include "street.h"

Street::Street(City* city1, City* city2)
{
    this->city1 = city1;
    this->city2 = city2;
}

void Street::draw(QGraphicsScene& scene)
{
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), QPen(Qt::green));
}

void Street::drawRed(QGraphicsScene& scene)
{
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(3);

    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), pen);
}

City* Street::getCity1() const
{
    return city1;
}

City* Street::getCity2() const
{
    return city2;
}
