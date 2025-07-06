#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>
#include <QRandomGenerator>

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

    int random = QRandomGenerator::global()->bounded(1000);

    bool ok;
    int i = lieblingsstadt.toInt(&ok);

    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Discard);
    msgBox.setDefaultButton(QMessageBox::Discard);

    if (ok)
    {
        qDebug() << QString("Zahl (+4): %1").arg(i+4);
        QString plusVier = QString("%1").arg(i+4);

        msgBox.setText("Zahl (+4): ");
        msgBox.setInformativeText(plusVier);
    }
    else
    {
        qDebug() << QString("Lieblingsstadt: %1").arg(lieblingsstadt);

        msgBox.setText("Lieblingsstadt:");
        msgBox.setInformativeText(lieblingsstadt);
    }

    msgBox.exec();
}
