#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "map.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    City getCity();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
    QVector<City> cities;
};

#endif // DIALOG_H
