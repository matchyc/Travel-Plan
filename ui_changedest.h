/********************************************************************************
** Form generated from reading UI file 'changedest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEDEST_H
#define UI_CHANGEDEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changeDest
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *finalDest;
    QLabel *label_2;
    QLineEdit *curDest;
    QLabel *label_3;
    QComboBox *expDest;

    void setupUi(QDialog *changeDest)
    {
        if (changeDest->objectName().isEmpty())
            changeDest->setObjectName(QString::fromUtf8("changeDest"));
        changeDest->resize(359, 274);
        buttonBox = new QDialogButtonBox(changeDest);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(changeDest);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 331, 201));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        finalDest = new QLineEdit(widget);
        finalDest->setObjectName(QString::fromUtf8("finalDest"));
        finalDest->setMaximumSize(QSize(65, 16777215));
        finalDest->setReadOnly(false);

        verticalLayout->addWidget(finalDest);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        curDest = new QLineEdit(widget);
        curDest->setObjectName(QString::fromUtf8("curDest"));
        curDest->setMaximumSize(QSize(65, 16777215));

        verticalLayout->addWidget(curDest);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        expDest = new QComboBox(widget);
        expDest->setObjectName(QString::fromUtf8("expDest"));
        expDest->setMaximumSize(QSize(90, 16777215));

        verticalLayout->addWidget(expDest);


        retranslateUi(changeDest);
        QObject::connect(buttonBox, SIGNAL(accepted()), changeDest, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), changeDest, SLOT(reject()));

        QMetaObject::connectSlotsByName(changeDest);
    } // setupUi

    void retranslateUi(QDialog *changeDest)
    {
        changeDest->setWindowTitle(QApplication::translate("changeDest", "Dialog", nullptr));
        label->setText(QApplication::translate("changeDest", "\346\234\200\347\273\210\347\233\256\347\232\204\345\234\260", nullptr));
        label_2->setText(QApplication::translate("changeDest", "\344\270\213\344\270\200\347\253\231", nullptr));
        label_3->setText(QApplication::translate("changeDest", "\346\234\237\346\234\233\346\233\264\346\224\271\347\232\204\347\233\256\347\232\204\345\234\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeDest: public Ui_changeDest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEDEST_H
