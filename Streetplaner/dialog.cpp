#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

City Dialog::getCity()
{
    return cities[0];
}

void Dialog::on_buttonBox_accepted()
{
    QString name = ui->lineEdit_cityName->text();
    int x = ui->spinBox_x->value();
    int y = ui->spinBox_y->value();

    City city(name, x, y);
    cities.push_back(city);
}

