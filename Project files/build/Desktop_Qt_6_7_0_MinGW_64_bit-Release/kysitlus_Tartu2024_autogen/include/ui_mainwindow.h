/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tartu2024
{
public:
    QWidget *centralwidget;
    QLabel *img2024;
    QLabel *ending;

    void setupUi(QMainWindow *Tartu2024)
    {
        if (Tartu2024->objectName().isEmpty())
            Tartu2024->setObjectName("Tartu2024");
        Tartu2024->resize(600, 400);
        Tartu2024->setMinimumSize(QSize(600, 400));
        Tartu2024->setMaximumSize(QSize(600, 400));
        Tartu2024->setBaseSize(QSize(600, 400));
        QPalette palette;
        QBrush brush(QColor(0, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(255, 255, 155, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        Tartu2024->setPalette(palette);
        QFont font;
        font.setPointSize(18);
        font.setWeight(QFont::Medium);
        Tartu2024->setFont(font);
        Tartu2024->setCursor(QCursor(Qt::PointingHandCursor));
        Tartu2024->setLayoutDirection(Qt::LeftToRight);
        Tartu2024->setAutoFillBackground(false);
        centralwidget = new QWidget(Tartu2024);
        centralwidget->setObjectName("centralwidget");
        img2024 = new QLabel(centralwidget);
        img2024->setObjectName("img2024");
        img2024->setGeometry(QRect(40, 100, 521, 261));
        ending = new QLabel(centralwidget);
        ending->setObjectName("ending");
        ending->setGeometry(QRect(100, 30, 401, 31));
        Tartu2024->setCentralWidget(centralwidget);

        retranslateUi(Tartu2024);

        QMetaObject::connectSlotsByName(Tartu2024);
    } // setupUi

    void retranslateUi(QMainWindow *Tartu2024)
    {
        Tartu2024->setWindowTitle(QCoreApplication::translate("Tartu2024", "Tartu2024", nullptr));
        img2024->setText(QString());
        ending->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tartu2024: public Ui_Tartu2024 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
