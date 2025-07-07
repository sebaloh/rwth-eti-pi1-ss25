#include "dialogstreet.h"
#include "ui_dialogstreet.h"

DialogStreet::DialogStreet(QWidget *parent, Map* map)
    : QDialog(parent)
    , ui(new Ui::DialogStreet)
{
    ui->setupUi(this);
    this->map = map;
}

DialogStreet::~DialogStreet()
{
    delete ui;
}

void DialogStreet::on_buttonBox_accepted()
{
    QString nameStart = QString(ui->lineEdit_CitStart->text());
    QString nameZiel = QString(ui->lineEdit_cityZiel->text());

    City* cityStart = map->findCity(nameStart);
    City* cityZiel = map->findCity(nameZiel);

    if(cityStart != nullptr && cityZiel != nullptr)
    {
        Street* street = new Street(cityStart, cityZiel);
        map->addStreet(street);
    }
}

