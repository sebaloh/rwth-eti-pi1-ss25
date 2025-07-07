/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionClear_Scene;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_testDijkstra;
    QPushButton *pushButton_addCity;
    QPushButton *pushButton_testMap;
    QSpacerItem *spacer;
    QLineEdit *lineEdit_cityStart;
    QLabel *label_eingabe;
    QCheckBox *checkBox_testVerbergen;
    QPushButton *pushButton_eingabe;
    QLineEdit *lineEdit_cityZiel;
    QPushButton *pushButton_addStreet;
    QPushButton *pushButton_fillMap;
    QPushButton *pushButton_testAbsMap;
    QPushButton *pushButton_testStreet;
    QPushButton *pushButton_testCity;
    QPushButton *pushButton_fileInput;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuScene;
    QMenu *menuInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionOpen->setEnabled(false);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave->setEnabled(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionClear_Scene = new QAction(MainWindow);
        actionClear_Scene->setObjectName("actionClear_Scene");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 1, 15, 1);

        pushButton_testDijkstra = new QPushButton(centralwidget);
        pushButton_testDijkstra->setObjectName("pushButton_testDijkstra");

        gridLayout->addWidget(pushButton_testDijkstra, 13, 0, 1, 1);

        pushButton_addCity = new QPushButton(centralwidget);
        pushButton_addCity->setObjectName("pushButton_addCity");

        gridLayout->addWidget(pushButton_addCity, 4, 0, 1, 1);

        pushButton_testMap = new QPushButton(centralwidget);
        pushButton_testMap->setObjectName("pushButton_testMap");

        gridLayout->addWidget(pushButton_testMap, 10, 0, 1, 1);

        spacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(spacer, 14, 0, 1, 1);

        lineEdit_cityStart = new QLineEdit(centralwidget);
        lineEdit_cityStart->setObjectName("lineEdit_cityStart");
        lineEdit_cityStart->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEdit_cityStart, 1, 0, 1, 1);

        label_eingabe = new QLabel(centralwidget);
        label_eingabe->setObjectName("label_eingabe");

        gridLayout->addWidget(label_eingabe, 0, 0, 1, 1);

        checkBox_testVerbergen = new QCheckBox(centralwidget);
        checkBox_testVerbergen->setObjectName("checkBox_testVerbergen");

        gridLayout->addWidget(checkBox_testVerbergen, 8, 0, 1, 1);

        pushButton_eingabe = new QPushButton(centralwidget);
        pushButton_eingabe->setObjectName("pushButton_eingabe");

        gridLayout->addWidget(pushButton_eingabe, 3, 0, 1, 1);

        lineEdit_cityZiel = new QLineEdit(centralwidget);
        lineEdit_cityZiel->setObjectName("lineEdit_cityZiel");

        gridLayout->addWidget(lineEdit_cityZiel, 2, 0, 1, 1);

        pushButton_addStreet = new QPushButton(centralwidget);
        pushButton_addStreet->setObjectName("pushButton_addStreet");

        gridLayout->addWidget(pushButton_addStreet, 5, 0, 1, 1);

        pushButton_fillMap = new QPushButton(centralwidget);
        pushButton_fillMap->setObjectName("pushButton_fillMap");

        gridLayout->addWidget(pushButton_fillMap, 6, 0, 1, 1);

        pushButton_testAbsMap = new QPushButton(centralwidget);
        pushButton_testAbsMap->setObjectName("pushButton_testAbsMap");

        gridLayout->addWidget(pushButton_testAbsMap, 12, 0, 1, 1);

        pushButton_testStreet = new QPushButton(centralwidget);
        pushButton_testStreet->setObjectName("pushButton_testStreet");

        gridLayout->addWidget(pushButton_testStreet, 11, 0, 1, 1);

        pushButton_testCity = new QPushButton(centralwidget);
        pushButton_testCity->setObjectName("pushButton_testCity");

        gridLayout->addWidget(pushButton_testCity, 9, 0, 1, 1);

        pushButton_fileInput = new QPushButton(centralwidget);
        pushButton_fileInput->setObjectName("pushButton_fileInput");

        gridLayout->addWidget(pushButton_fileInput, 7, 0, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuScene = new QMenu(menuBar);
        menuScene->setObjectName("menuScene");
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName("menuInfo");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuScene->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuScene->addAction(actionClear_Scene);
        menuInfo->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Alt+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear_Scene->setText(QCoreApplication::translate("MainWindow", "Clear Scene", nullptr));
#if QT_CONFIG(shortcut)
        actionClear_Scene->setShortcut(QCoreApplication::translate("MainWindow", "Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        pushButton_testDijkstra->setText(QCoreApplication::translate("MainWindow", "Test Dijkstra", nullptr));
        pushButton_addCity->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        pushButton_testMap->setText(QCoreApplication::translate("MainWindow", "Test Map", nullptr));
        lineEdit_cityStart->setPlaceholderText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_eingabe->setText(QCoreApplication::translate("MainWindow", "Djikstra Suche", nullptr));
        checkBox_testVerbergen->setText(QCoreApplication::translate("MainWindow", "Test verbergen", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_eingabe->setToolTip(QCoreApplication::translate("MainWindow", "Sucht die eingegebene Stadt", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_eingabe->setText(QCoreApplication::translate("MainWindow", "Suchen", nullptr));
        lineEdit_cityZiel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ziel", nullptr));
        pushButton_addStreet->setText(QCoreApplication::translate("MainWindow", "Add Street", nullptr));
        pushButton_fillMap->setText(QCoreApplication::translate("MainWindow", "Fill Map", nullptr));
        pushButton_testAbsMap->setText(QCoreApplication::translate("MainWindow", "Test Abstract Map", nullptr));
        pushButton_testStreet->setText(QCoreApplication::translate("MainWindow", "Test Street", nullptr));
        pushButton_testCity->setText(QCoreApplication::translate("MainWindow", "Test City", nullptr));
        pushButton_fileInput->setText(QCoreApplication::translate("MainWindow", "File Input", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuScene->setTitle(QCoreApplication::translate("MainWindow", "Scene", nullptr));
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
