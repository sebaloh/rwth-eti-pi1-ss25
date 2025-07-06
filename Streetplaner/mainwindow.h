#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QRandomGenerator>
#include <QMessageBox>
#include "map.h"
#include "dialog.h"
#include "mapio.h"
#include "mapionrw.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_eingabe_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_testCity_clicked();

    void on_pushButton_testMap_clicked();

    void on_pushButton_testStreet_clicked();

    void on_checkBox_testVerbergen_clicked();

    void on_pushButton_addCity_clicked();

    void on_pushButton_fillMap_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapio;
};
#endif // MAINWINDOW_H
