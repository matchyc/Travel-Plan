/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <chinamap.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_1h_s;
    QAction *action_1h_10s;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    chinaMap *myMap;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QLCDNumber *masterTimeLcd;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addTravelerButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLCDNumber *sumOfTravelersLcdNumber;
    QLabel *movieLabel;
    QPushButton *citysSecurityButton;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *checkTravcomboBox;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *expArriveTime;
    QLabel *label_4;
    QTableView *tablePlanView;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *lookUpButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *changeDestButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1154, 777);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_1h_s = new QAction(MainWindow);
        action_1h_s->setObjectName(QString::fromUtf8("action_1h_s"));
        action_1h_10s = new QAction(MainWindow);
        action_1h_10s->setObjectName(QString::fromUtf8("action_1h_10s"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        myMap = new chinaMap(centralWidget);
        myMap->setObjectName(QString::fromUtf8("myMap"));
        myMap->setAutoFillBackground(true);

        horizontalLayout->addWidget(myMap);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        masterTimeLcd = new QLCDNumber(frame);
        masterTimeLcd->setObjectName(QString::fromUtf8("masterTimeLcd"));

        gridLayout->addWidget(masterTimeLcd, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addTravelerButton = new QPushButton(widget);
        addTravelerButton->setObjectName(QString::fromUtf8("addTravelerButton"));

        horizontalLayout_2->addWidget(addTravelerButton);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        sumOfTravelersLcdNumber = new QLCDNumber(widget_2);
        sumOfTravelersLcdNumber->setObjectName(QString::fromUtf8("sumOfTravelersLcdNumber"));

        horizontalLayout_3->addWidget(sumOfTravelersLcdNumber);


        horizontalLayout_2->addWidget(widget_2, 0, Qt::AlignVCenter);


        gridLayout->addWidget(widget, 2, 1, 1, 1, Qt::AlignTop);

        movieLabel = new QLabel(frame);
        movieLabel->setObjectName(QString::fromUtf8("movieLabel"));

        gridLayout->addWidget(movieLabel, 4, 1, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        citysSecurityButton = new QPushButton(frame);
        citysSecurityButton->setObjectName(QString::fromUtf8("citysSecurityButton"));

        gridLayout->addWidget(citysSecurityButton, 1, 1, 1, 1);

        widget_3 = new QWidget(frame);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(11, 11, -1, -1);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        checkTravcomboBox = new QComboBox(widget_4);
        checkTravcomboBox->setObjectName(QString::fromUtf8("checkTravcomboBox"));

        horizontalLayout_4->addWidget(checkTravcomboBox);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        expArriveTime = new QLineEdit(widget_5);
        expArriveTime->setObjectName(QString::fromUtf8("expArriveTime"));

        horizontalLayout_5->addWidget(expArriveTime);


        verticalLayout_2->addWidget(widget_5);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        tablePlanView = new QTableView(widget_3);
        tablePlanView->setObjectName(QString::fromUtf8("tablePlanView"));
        tablePlanView->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(tablePlanView);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lookUpButton = new QPushButton(widget_6);
        lookUpButton->setObjectName(QString::fromUtf8("lookUpButton"));

        horizontalLayout_6->addWidget(lookUpButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        changeDestButton = new QPushButton(widget_6);
        changeDestButton->setObjectName(QString::fromUtf8("changeDestButton"));

        horizontalLayout_6->addWidget(changeDestButton);


        verticalLayout_2->addWidget(widget_6);


        gridLayout->addWidget(widget_3, 3, 1, 1, 1, Qt::AlignHCenter|Qt::AlignTop);


        horizontalLayout->addWidget(frame, 0, Qt::AlignTop);

        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        myMap->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1154, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_1h_s);
        menu->addAction(action_1h_10s);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\344\272\244\351\200\232\346\227\266\345\210\273\350\241\250", nullptr));
        action_1h_s->setText(QApplication::translate("MainWindow", "\345\277\253\351\200\2371h/s", nullptr));
        action_1h_10s->setText(QApplication::translate("MainWindow", "\346\205\242\351\200\2371h/10s", nullptr));
        addTravelerButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\227\205\345\256\242", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\205\345\256\242\346\200\273\346\225\260\357\274\232", nullptr));
        movieLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        citysSecurityButton->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\220\204\345\237\216\345\270\202\351\243\216\351\231\251\347\255\211\347\272\247", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\246\201\346\237\245\347\234\213\347\212\266\346\200\201\347\232\204\346\227\205\345\256\242", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\351\242\204\350\256\241\345\210\260\350\276\276\347\233\256\347\232\204\345\234\260\346\227\266\351\227\264", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\344\271\230\345\256\242\350\241\214\347\250\213\350\241\250:", nullptr));
        lookUpButton->setText(QApplication::translate("MainWindow", "\346\211\200\346\234\211\350\267\257\347\272\277\346\237\245\350\257\242", nullptr));
        changeDestButton->setText(QApplication::translate("MainWindow", "\346\233\264\346\224\271\345\275\223\345\211\215\346\227\205\345\256\242\347\233\256\347\232\204\345\234\260", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
