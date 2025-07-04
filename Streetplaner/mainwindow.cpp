#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDebug>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_eingabe_clicked()
{
    QString lieblingsstadt = ui->lineEdit_eingabe->text();

    bool ok;
    int i = lieblingsstadt.toInt(&ok);

    if (ok)
    {
        qDebug() << QString("Zahl (+4): %1").arg(i+4);
    }
    else
    {
        qDebug() << QString("Lieblingsstadt: %1").arg(lieblingsstadt);
    }
}
