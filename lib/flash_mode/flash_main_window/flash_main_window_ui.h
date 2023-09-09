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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlashLanderMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *central_widget_layout;
    QGroupBox *groupBox;
    QAxWidget *seer_flash_game_window_axWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *setting;
    QMenu *option;

    void setupUi(QMainWindow *FlashLanderMainWindow)
    {
        if (FlashLanderMainWindow->objectName().isEmpty())
            FlashLanderMainWindow->setObjectName(QString::fromUtf8("FlashLanderMainWindow"));
        FlashLanderMainWindow->resize(960, 582);
        FlashLanderMainWindow->setMinimumSize(QSize(480, 280));
        centralwidget = new QWidget(FlashLanderMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(480, 280));
        central_widget_layout = new QVBoxLayout(centralwidget);
        central_widget_layout->setSpacing(0);
        central_widget_layout->setObjectName(QString::fromUtf8("central_widget_layout"));
        central_widget_layout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(480, 280));
        seer_flash_game_window_axWidget = new QAxWidget(groupBox);
        seer_flash_game_window_axWidget->setObjectName(QString::fromUtf8("seer_flash_game_window_axWidget"));
        seer_flash_game_window_axWidget->setProperty("geometry", QVariant(QRect(0, 0, 960, 560)));
        seer_flash_game_window_axWidget->setProperty("minimumSize", QVariant(QSize(480, 280)));

        central_widget_layout->addWidget(groupBox);

        FlashLanderMainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(FlashLanderMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 960, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(269, 127, 120, 50));
        setting = new QMenu(menuBar);
        setting->setObjectName(QString::fromUtf8("setting"));
        option = new QMenu(menuBar);
        option->setObjectName(QString::fromUtf8("option"));
        FlashLanderMainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(setting->menuAction());
        menuBar->addAction(option->menuAction());

        retranslateUi(FlashLanderMainWindow);

        QMetaObject::connectSlotsByName(FlashLanderMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FlashLanderMainWindow)
    {
        FlashLanderMainWindow->setWindowTitle(QApplication::translate("FlashLanderMainWindow", "FLASH\346\250\241\345\274\217", nullptr));
        groupBox->setTitle(QApplication::translate("FlashLanderMainWindow", "GroupBox", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        seer_flash_game_window_axWidget->setProperty("accessibleName", QVariant(QString()));
#endif // QT_NO_ACCESSIBILITY
        menu->setTitle(QApplication::translate("FlashLanderMainWindow", "\350\217\234\345\215\225", nullptr));
        setting->setTitle(QApplication::translate("FlashLanderMainWindow", "\350\256\276\347\275\256", nullptr));
        option->setTitle(QApplication::translate("FlashLanderMainWindow", "\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlashLanderMainWindow: public Ui_FlashLanderMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FLASH_MAIN_WINDOW_UI_H
