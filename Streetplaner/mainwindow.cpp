#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_eingabe_clicked()
{
    int randomX = QRandomGenerator::global()->bounded(1000);
    int randomY = QRandomGenerator::global()->bounded(1000);
    scene.addRect(randomX, randomY, 10, 10, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));
}

void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.about(this, "Streetplaner", "RWTH ETI PI1 SS25");
}


void MainWindow::on_pushButton_testDrawCity_clicked()
{
    City c1("c1", 20, 50);
    c1.draw(scene);
    City c2("c2", 30, 10);
    c2.draw(scene);
}


void MainWindow::on_pushButton_testMap_clicked()
{
    City c1("city c1", 20,50);
    map.addCity(&c1);
    map.draw(scene);
}

