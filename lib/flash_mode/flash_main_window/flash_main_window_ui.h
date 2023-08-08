/********************************************************************************
** Form generated from reading UI file 'flash_main_window_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FLASH_MAIN_WINDOW_UI_H
#define FLASH_MAIN_WINDOW_UI_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlashLanderMainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QAxWidget *seer_flash_game_window_axWidget;
    QComboBox *comboBox;
    QCheckBox *audio_mute_checkBox;

    void setupUi(QMainWindow *FlashLanderMainWindow)
    {
        if (FlashLanderMainWindow->objectName().isEmpty())
            FlashLanderMainWindow->setObjectName(QString::fromUtf8("FlashLanderMainWindow"));
        FlashLanderMainWindow->resize(960, 580);
        FlashLanderMainWindow->setMinimumSize(QSize(480, 280));
        centralwidget = new QWidget(FlashLanderMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(480, 280));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 20, 960, 560));
        seer_flash_game_window_axWidget = new QAxWidget(groupBox);
        seer_flash_game_window_axWidget->setObjectName(QString::fromUtf8("seer_flash_game_window_axWidget"));
        seer_flash_game_window_axWidget->setGeometry(QRect(0, 0, 980, 580));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(0, 0, 75, 20));
        audio_mute_checkBox = new QCheckBox(centralwidget);
        audio_mute_checkBox->setObjectName(QString::fromUtf8("audio_mute_checkBox"));
        audio_mute_checkBox->setGeometry(QRect(910, 0, 50, 20));
        FlashLanderMainWindow->setCentralWidget(centralwidget);

        retranslateUi(FlashLanderMainWindow);

        QMetaObject::connectSlotsByName(FlashLanderMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FlashLanderMainWindow)
    {
        FlashLanderMainWindow->setWindowTitle(QApplication::translate("FlashLanderMainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("FlashLanderMainWindow", "GroupBox", nullptr));
        comboBox->setCurrentText(QString());
        audio_mute_checkBox->setText(QApplication::translate("FlashLanderMainWindow", "\351\235\231\351\237\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlashLanderMainWindow: public Ui_FlashLanderMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FLASH_MAIN_WINDOW_UI_H
