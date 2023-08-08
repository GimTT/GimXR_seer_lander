/********************************************************************************
** Form generated from reading UI file 'startup_options.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STARTUP_OPTIONS_UI_H
#define STARTUP_OPTIONS_UI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "../../lander_conf.h"

QT_BEGIN_NAMESPACE

class Ui_StartupModeWindow
{
public:
    QWidget *centralwidget;
    QPushButton *flash_mode_btn;
    QPushButton *h5_mode_btn;

    void setupUi(QMainWindow *StartupModeWindow)
    {
        if (StartupModeWindow->objectName().isEmpty())
            StartupModeWindow->setObjectName(QString::fromUtf8("StartupModeWindow"));
        StartupModeWindow->resize(640, 140);
        centralwidget = new QWidget(StartupModeWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        flash_mode_btn = new QPushButton(centralwidget);
        flash_mode_btn->setObjectName(QString::fromUtf8("flash_mode_btn"));
        flash_mode_btn->setGeometry(QRect(0, 0, 320, 140));
        QIcon icon;
#if DEV_MODE
        icon.addFile(QString::fromUtf8("E:/GimXR_Workspace/GimXR_seer_lander/seer_lander/lib/startup_options/Flash_Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
#else
        icon.addFile(QString::fromUtf8("startup_options/Flash_Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
#endif
        flash_mode_btn->setIcon(icon);
        flash_mode_btn->setIconSize(QSize(320, 320));
        h5_mode_btn = new QPushButton(centralwidget);
        h5_mode_btn->setObjectName(QString::fromUtf8("h5_mode_btn"));
        h5_mode_btn->setGeometry(QRect(320, 0, 320, 140));
        QIcon icon1;
#if DEV_MODE
        icon1.addFile(QString::fromUtf8("E:/GimXR_Workspace/GimXR_seer_lander/seer_lander/lib/startup_options/H5_Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
#else
        icon1.addFile(QString::fromUtf8("startup_options/H5_Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
#endif
        h5_mode_btn->setIcon(icon1);
        h5_mode_btn->setIconSize(QSize(320, 320));
        StartupModeWindow->setCentralWidget(centralwidget);

        retranslateUi(StartupModeWindow);

        QMetaObject::connectSlotsByName(StartupModeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartupModeWindow)
    {
        StartupModeWindow->setWindowTitle(QApplication::translate("StartupModeWindow", "\351\200\211\346\213\251\346\250\241\345\274\217", nullptr));
        flash_mode_btn->setText(QString());
        h5_mode_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartupModeWindow: public Ui_StartupModeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STARTUP_OPTIONS_UI_H
