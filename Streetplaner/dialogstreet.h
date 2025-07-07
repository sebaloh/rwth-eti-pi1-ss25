#ifndef DIALOGSTREET_H
#define DIALOGSTREET_H

#include <QDialog>

#include "map.h"

namespace Ui {
class DialogStreet;
}

class DialogStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStreet(QWidget *parent = nullptr, Map* map = nullptr);
    ~DialogStreet();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogStreet *ui;
    Map* map;
};

#endif // DIALOGSTREET_H
