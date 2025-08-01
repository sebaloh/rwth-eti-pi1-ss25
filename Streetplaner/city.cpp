#include "city.h"

City::City(QString name, int x, int y)
{
    this->name = name;
    this->x = x;
    this->y = y;
}

void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse(x, y, 5, 5, QPen(Qt::green), QBrush(Qt::green, Qt::SolidPattern));

    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(x, y);
    text->setPlainText(name);
    scene.addItem( text );

    qDebug() << QString("Add %1 at %2, %3.").arg(name).arg(x).arg(y);
}

QString City::getName()
{
    return name;
}

int City::getX()
{
    return x;
}

int City::getY()
{
    return y;
}
