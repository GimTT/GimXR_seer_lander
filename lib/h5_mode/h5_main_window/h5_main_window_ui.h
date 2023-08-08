/********************************************************************************
** Form generated from reading UI file 'h5_main_window_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef H5_MAIN_WINDOW_UI_H
#define H5_MAIN_WINDOW_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_H5LanderMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *refresh_btn;
    QCheckBox *audio_mute_checkBox;
    QFrame *seer_h5_game_window_frame;

    void setupUi(QMainWindow *H5LanderMainWindow)
    {
        if (H5LanderMainWindow->objectName().isEmpty())
            H5LanderMainWindow->setObjectName(QString::fromUtf8("H5LanderMainWindow"));
        H5LanderMainWindow->resize(960, 580);
        H5LanderMainWindow->setMinimumSize(QSize(960, 580));
        centralwidget = new QWidget(H5LanderMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(960, 580));
        centralwidget->setMaximumSize(QSize(980, 580));
        refresh_btn = new QPushButton(centralwidget);
        refresh_btn->setObjectName(QString::fromUtf8("refresh_btn"));
        refresh_btn->setGeometry(QRect(0, 0, 50, 20));
        audio_mute_checkBox = new QCheckBox(centralwidget);
        audio_mute_checkBox->setObjectName(QString::fromUtf8("audio_mute_checkBox"));
        audio_mute_checkBox->setGeometry(QRect(910, 0, 50, 20));
        seer_h5_game_window_frame = new QFrame(centralwidget);
        seer_h5_game_window_frame->setObjectName(QString::fromUtf8("seer_h5_game_window_frame"));
        seer_h5_game_window_frame->setGeometry(QRect(0, 20, 960, 560));
        H5LanderMainWindow->setCentralWidget(centralwidget);

        retranslateUi(H5LanderMainWindow);

        QMetaObject::connectSlotsByName(H5LanderMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *H5LanderMainWindow)
    {
        H5LanderMainWindow->setWindowTitle(QApplication::translate("H5LanderMainWindow", "H5\346\250\241\345\274\217", nullptr));
        refresh_btn->setText(QApplication::translate("H5LanderMainWindow", "\345\210\267\346\226\260", nullptr));
        audio_mute_checkBox->setText(QApplication::translate("H5LanderMainWindow", "\351\235\231\351\237\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class H5LanderMainWindow: public Ui_H5LanderMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // H5_MAIN_WINDOW_UI_H
