/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_cityName;
    QSpinBox *spinBox_x;
    QSpinBox *spinBox_y;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;
    QLabel *label_x;
    QLabel *label_y;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        formLayout = new QFormLayout(Dialog);
        formLayout->setObjectName("formLayout");
        label = new QLabel(Dialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        lineEdit_cityName = new QLineEdit(Dialog);
        lineEdit_cityName->setObjectName("lineEdit_cityName");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, lineEdit_cityName);

        spinBox_x = new QSpinBox(Dialog);
        spinBox_x->setObjectName("spinBox_x");
        spinBox_x->setMaximum(999);

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, spinBox_x);

        spinBox_y = new QSpinBox(Dialog);
        spinBox_y->setObjectName("spinBox_y");
        spinBox_y->setMaximum(999);

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, spinBox_y);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, buttonBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(6, QFormLayout::ItemRole::LabelRole, verticalSpacer);

        label_x = new QLabel(Dialog);
        label_x->setObjectName("label_x");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_x);

        label_y = new QLabel(Dialog);
        label_y->setObjectName("label_y");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_y);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Neue Stadt", nullptr));
        lineEdit_cityName->setInputMask(QString());
        lineEdit_cityName->setText(QString());
        lineEdit_cityName->setPlaceholderText(QCoreApplication::translate("Dialog", "Name", nullptr));
        label_x->setText(QCoreApplication::translate("Dialog", "X-Koordinate", nullptr));
        label_y->setText(QCoreApplication::translate("Dialog", "Y-Koordinate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
