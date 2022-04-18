/********************************************************************************
** Form generated from reading UI file 'lookupallroutes.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOKUPALLROUTES_H
#define UI_LOOKUPALLROUTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lookUpAllRoutes
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QComboBox *srcComboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *destComboBox;
    QSpacerItem *horizontalSpacer_3;
    QTableView *planDisplayView;

    void setupUi(QDialog *lookUpAllRoutes)
    {
        if (lookUpAllRoutes->objectName().isEmpty())
            lookUpAllRoutes->setObjectName(QString::fromUtf8("lookUpAllRoutes"));
        lookUpAllRoutes->resize(485, 367);
        verticalLayout = new QVBoxLayout(lookUpAllRoutes);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(lookUpAllRoutes);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        srcComboBox = new QComboBox(widget);
        srcComboBox->setObjectName(QString::fromUtf8("srcComboBox"));

        horizontalLayout->addWidget(srcComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        destComboBox = new QComboBox(widget);
        destComboBox->setObjectName(QString::fromUtf8("destComboBox"));

        horizontalLayout->addWidget(destComboBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget);

        planDisplayView = new QTableView(lookUpAllRoutes);
        planDisplayView->setObjectName(QString::fromUtf8("planDisplayView"));

        verticalLayout->addWidget(planDisplayView);


        retranslateUi(lookUpAllRoutes);

        QMetaObject::connectSlotsByName(lookUpAllRoutes);
    } // setupUi

    void retranslateUi(QDialog *lookUpAllRoutes)
    {
        lookUpAllRoutes->setWindowTitle(QApplication::translate("lookUpAllRoutes", "Dialog", nullptr));
        label->setText(QApplication::translate("lookUpAllRoutes", "\345\207\272\345\217\221\345\234\260", nullptr));
        label_2->setText(QApplication::translate("lookUpAllRoutes", "\347\233\256\347\232\204\345\234\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lookUpAllRoutes: public Ui_lookUpAllRoutes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOKUPALLROUTES_H
