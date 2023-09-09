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
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_H5LanderMainWindow
{
public:
    QWidget *centralwidget;
    QWebEngineView *seer_h5_view;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *H5LanderMainWindow)
    {
        if (H5LanderMainWindow->objectName().isEmpty())
            H5LanderMainWindow->setObjectName(QString::fromUtf8("H5LanderMainWindow"));
        H5LanderMainWindow->resize(960, 580);
        H5LanderMainWindow->setMinimumSize(QSize(320, 240));
        centralwidget = new QWidget(H5LanderMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(320, 240));
        centralwidget->setMaximumSize(QSize(16777215, 16777215));
        seer_h5_view = new QWebEngineView(centralwidget);
        seer_h5_view->setObjectName(QString::fromUtf8("seer_h5_view"));
        seer_h5_view->setGeometry(QRect(0, 0, 960, 560));
        seer_h5_view->setMinimumSize(QSize(320, 240));
        seer_h5_view->setUrl(QUrl(QString::fromUtf8("about:blank")));
        H5LanderMainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(H5LanderMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 960, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        H5LanderMainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(H5LanderMainWindow);

        QMetaObject::connectSlotsByName(H5LanderMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *H5LanderMainWindow)
    {
        H5LanderMainWindow->setWindowTitle(QApplication::translate("H5LanderMainWindow", "H5\346\250\241\345\274\217", nullptr));
        menu->setTitle(QApplication::translate("H5LanderMainWindow", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class H5LanderMainWindow: public Ui_H5LanderMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // H5_MAIN_WINDOW_UI_H
