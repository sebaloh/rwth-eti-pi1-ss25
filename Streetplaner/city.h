#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class City
{
public:
    City(QString name, int x, int y);
    void draw(QGraphicsScene& scene);
    QString getName();
    int getX();
    int getY();
private:
    QString name;
    int x;
    int y;
};

#endif // CITY_H
