/********************************************************************************
** Form generated from reading UI file 'addtravelerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTRAVELERDIALOG_H
#define UI_ADDTRAVELERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addTravelerDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *strategyComboBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QComboBox *srcComboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *destComboBox;
    QWidget *widget_4;
    QLabel *label_5;
    QLineEdit *limitEdit;
    QPushButton *calcButton;

    void setupUi(QDialog *addTravelerDialog)
    {
        if (addTravelerDialog->objectName().isEmpty())
            addTravelerDialog->setObjectName(QString::fromUtf8("addTravelerDialog"));
        addTravelerDialog->resize(532, 430);
        buttonBox = new QDialogButtonBox(addTravelerDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(150, 360, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(addTravelerDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 451, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\350\277\267\344\275\240\347\256\200\344\270\255\347\211\271\345\271\277\345\221\212"));
        font.setPointSize(13);
        label->setFont(font);
        widget_3 = new QWidget(addTravelerDialog);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(40, 50, 411, 161));
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(20, 90, 176, 43));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        strategyComboBox = new QComboBox(widget_2);
        strategyComboBox->setObjectName(QString::fromUtf8("strategyComboBox"));

        horizontalLayout_2->addWidget(strategyComboBox);

        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 307, 43));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        srcComboBox = new QComboBox(widget);
        srcComboBox->setObjectName(QString::fromUtf8("srcComboBox"));

        horizontalLayout->addWidget(srcComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        destComboBox = new QComboBox(widget);
        destComboBox->setObjectName(QString::fromUtf8("destComboBox"));

        horizontalLayout->addWidget(destComboBox);

        widget_4 = new QWidget(addTravelerDialog);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(40, 220, 411, 51));
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 10, 241, 21));
        limitEdit = new QLineEdit(widget_4);
        limitEdit->setObjectName(QString::fromUtf8("limitEdit"));
        limitEdit->setGeometry(QRect(280, 10, 113, 21));
        limitEdit->setMaxLength(32767);
        limitEdit->setFrame(true);
        limitEdit->setDragEnabled(false);
        calcButton = new QPushButton(addTravelerDialog);
        calcButton->setObjectName(QString::fromUtf8("calcButton"));
        calcButton->setGeometry(QRect(120, 290, 271, 31));

        retranslateUi(addTravelerDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), addTravelerDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), addTravelerDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(addTravelerDialog);
    } // setupUi

    void retranslateUi(QDialog *addTravelerDialog)
    {
        addTravelerDialog->setWindowTitle(QApplication::translate("addTravelerDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("addTravelerDialog", "\345\260\212\346\225\254\347\232\204\346\227\205\345\256\242\346\202\250\345\245\275\357\274\201\350\257\267\351\200\211\346\213\251\346\202\250\347\232\204\345\207\272\345\217\221\345\234\260\345\222\214\347\233\256\347\232\204\345\234\260", nullptr));
        label_4->setText(QApplication::translate("addTravelerDialog", "\347\255\226\347\225\245\351\200\211\346\213\251", nullptr));
        label_2->setText(QApplication::translate("addTravelerDialog", "\345\207\272\345\217\221\345\234\260", nullptr));
        label_3->setText(QApplication::translate("addTravelerDialog", "\347\233\256\347\232\204\345\234\260", nullptr));
        label_5->setText(QApplication::translate("addTravelerDialog", "\350\276\223\345\205\245\346\202\250\350\203\275\346\216\245\345\217\227\347\232\204\346\227\266\351\227\264\346\266\210\350\200\227\357\274\210\345\260\217\346\227\266\357\274\211\357\274\232", nullptr));
        calcButton->setText(QApplication::translate("addTravelerDialog", "\346\263\250\346\204\217\357\274\232\350\265\267\347\202\271\347\273\210\347\202\271\344\270\200\350\207\264\345\210\231\350\247\206\344\270\272\346\227\240\346\225\210\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addTravelerDialog: public Ui_addTravelerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRAVELERDIALOG_H
