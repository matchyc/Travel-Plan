/********************************************************************************
** Form generated from reading UI file 'chinamap.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHINAMAP_H
#define UI_CHINAMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chinaMap
{
public:
    QLabel *myLabel;
    QLabel *riskValueLabel;

    void setupUi(QWidget *chinaMap)
    {
        if (chinaMap->objectName().isEmpty())
            chinaMap->setObjectName(QString::fromUtf8("chinaMap"));
        chinaMap->resize(1000, 900);
        chinaMap->setMinimumSize(QSize(1000, 900));
        chinaMap->setMaximumSize(QSize(1000, 900));
        myLabel = new QLabel(chinaMap);
        myLabel->setObjectName(QString::fromUtf8("myLabel"));
        myLabel->setGeometry(QRect(60, 90, 131, 51));
        riskValueLabel = new QLabel(chinaMap);
        riskValueLabel->setObjectName(QString::fromUtf8("riskValueLabel"));
        riskValueLabel->setGeometry(QRect(570, 70, 221, 71));
        riskValueLabel->setStyleSheet(QString::fromUtf8("color: rgb(227, 0, 0);\n"
"font: 18pt \"\345\256\213\344\275\223\";"));

        retranslateUi(chinaMap);

        QMetaObject::connectSlotsByName(chinaMap);
    } // setupUi

    void retranslateUi(QWidget *chinaMap)
    {
        chinaMap->setWindowTitle(QApplication::translate("chinaMap", "Form", nullptr));
        myLabel->setText(QApplication::translate("chinaMap", "TextLabel", nullptr));
        riskValueLabel->setText(QApplication::translate("chinaMap", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chinaMap: public Ui_chinaMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHINAMAP_H
