/********************************************************************************
** Form generated from reading UI file 'dm_window_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DM_WINDOW_UI_H
#define DM_WINDOW_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DmWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *file_index_line_edit;
    QSpinBox *loop_cont_spin_box;
    QPushButton *select_push_button;
    QPushButton *run_push_button;
    QLabel *next_action_label;

    void setupUi(QMainWindow *DmWindow)
    {
        if (DmWindow->objectName().isEmpty())
            DmWindow->setObjectName(QString::fromUtf8("DmWindow"));
        DmWindow->resize(300, 75);
        DmWindow->setMinimumSize(QSize(300, 75));
        DmWindow->setMaximumSize(QSize(300, 75));
        centralwidget = new QWidget(DmWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        file_index_line_edit = new QLineEdit(centralwidget);
        file_index_line_edit->setObjectName(QString::fromUtf8("file_index_line_edit"));
        file_index_line_edit->setGeometry(QRect(10, 10, 221, 23));
        loop_cont_spin_box = new QSpinBox(centralwidget);
        loop_cont_spin_box->setObjectName(QString::fromUtf8("loop_cont_spin_box"));
        loop_cont_spin_box->setGeometry(QRect(190, 40, 42, 22));
        select_push_button = new QPushButton(centralwidget);
        select_push_button->setObjectName(QString::fromUtf8("select_push_button"));
        select_push_button->setGeometry(QRect(240, 9, 50, 25));
        run_push_button = new QPushButton(centralwidget);
        run_push_button->setObjectName(QString::fromUtf8("run_push_button"));
        run_push_button->setGeometry(QRect(240, 39, 50, 25));
        next_action_label = new QLabel(centralwidget);
        next_action_label->setObjectName(QString::fromUtf8("next_action_label"));
        next_action_label->setGeometry(QRect(5, 51, 180, 23));
        DmWindow->setCentralWidget(centralwidget);

        retranslateUi(DmWindow);

        QMetaObject::connectSlotsByName(DmWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DmWindow)
    {
        DmWindow->setWindowTitle(QApplication::translate("DmWindow", "\350\207\252\345\256\232\344\271\211\350\204\232\346\234\254", nullptr));
        select_push_button->setText(QApplication::translate("DmWindow", "\351\200\211\346\213\251", nullptr));
        run_push_button->setText(QApplication::translate("DmWindow", "\346\211\247\350\241\214", nullptr));
        next_action_label->setText(QApplication::translate("DmWindow", "\345\260\261\347\273\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DmWindow: public Ui_DmWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DM_WINDOW_UI_H
