#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&scene);

    MapIoNrw mapionrw;
    mapionrw.fillMap(map);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_eingabe_clicked()
{
    QString cityStart = QString(ui->lineEdit_cityStart->text());
    QString cityZiel = QString(ui->lineEdit_cityZiel->text());

    QVector<Street*> streets = Dijkstra::search(map, cityStart, cityZiel);

    for(Street* street : streets)
    {
        street->drawRed(scene);
    }
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


void MainWindow::on_pushButton_testCity_clicked()
{
    City c1("c1", 20, 50);
    c1.draw(scene);
    City c2("c2", 30, 10);
    c2.draw(scene);
}


void MainWindow::on_pushButton_testMap_clicked()
{
    City c1("c1", 20, 50);
    map.addCity(&c1);
    City c2("c2", 30, 10);
    map.addCity(&c2);
    Street s1(&c1, &c2);
    map.addStreet(&s1);
    map.draw(scene);
}


void MainWindow::on_pushButton_testStreet_clicked()
{
    City c1("c1", 20, 50);
    c1.draw(scene);
    City c2("c2", 30, 10);
    c2.draw(scene);
    Street s1(&c1, &c2);
    s1.draw(scene);
}


void MainWindow::on_checkBox_testVerbergen_clicked()
{
    if(ui->checkBox_testVerbergen->isChecked())
    {
        ui->pushButton_testCity->hide();
        ui->pushButton_testMap->hide();
        ui->pushButton_testStreet->hide();
        ui->pushButton_testAbsMap->hide();
        ui->pushButton_testDijkstra->hide();
    }
    else
    {
        ui->pushButton_testCity->show();
        ui->pushButton_testMap->show();
        ui->pushButton_testStreet->show();
        ui->pushButton_testAbsMap->show();
        ui->pushButton_testDijkstra->show();
    }
}


void MainWindow::on_pushButton_addCity_clicked()
{
    Dialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        City newCity = dialog.getCity();
        map.addCity(&newCity);
        map.draw(scene);
    }
}


void MainWindow::on_pushButton_fillMap_clicked()
{
    map.draw(scene);
}


void MainWindow::on_pushButton_testAbsMap_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_pushButton_testDijkstra_clicked()
{
    QVector<Street*> streets = Dijkstra::search(map, QString("Aachen"), QString("Düsseldorf"));

    qDebug() << QString("Von %1 zu %2 und %3 zu %4").arg(streets[0]->getCity1()->getName()).arg(streets[0]->getCity2()->getName()).arg(streets[1]->getCity1()->getName()).arg(streets[1]->getCity2()->getName());

    for(Street* street : streets)
    {
        street->drawRed(scene);
    }
}


void MainWindow::on_pushButton_addStreet_clicked()
{
    DialogStreet dialogStreet(this, &map);
    dialogStreet.exec();
    map.draw(scene);
}
