/********************************************************************************
** Form generated from reading UI file 'dialogstreet.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSTREET_H
#define UI_DIALOGSTREET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DialogStreet
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_CitStart;
    QLineEdit *lineEdit_cityZiel;

    void setupUi(QDialog *DialogStreet)
    {
        if (DialogStreet->objectName().isEmpty())
            DialogStreet->setObjectName("DialogStreet");
        DialogStreet->resize(400, 300);
        formLayout = new QFormLayout(DialogStreet);
        formLayout->setObjectName("formLayout");
        label = new QLabel(DialogStreet);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        buttonBox = new QDialogButtonBox(DialogStreet);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, buttonBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(3, QFormLayout::ItemRole::LabelRole, verticalSpacer);

        lineEdit_CitStart = new QLineEdit(DialogStreet);
        lineEdit_CitStart->setObjectName("lineEdit_CitStart");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, lineEdit_CitStart);

        lineEdit_cityZiel = new QLineEdit(DialogStreet);
        lineEdit_cityZiel->setObjectName("lineEdit_cityZiel");
        lineEdit_cityZiel->setClearButtonEnabled(true);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, lineEdit_cityZiel);


        retranslateUi(DialogStreet);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogStreet, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogStreet, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogStreet);
    } // setupUi

    void retranslateUi(QDialog *DialogStreet)
    {
        DialogStreet->setWindowTitle(QCoreApplication::translate("DialogStreet", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogStreet", "Add Street", nullptr));
        lineEdit_CitStart->setPlaceholderText(QCoreApplication::translate("DialogStreet", "Start", nullptr));
        lineEdit_cityZiel->setPlaceholderText(QCoreApplication::translate("DialogStreet", "Ziel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogStreet: public Ui_DialogStreet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSTREET_H
