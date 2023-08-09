/********************************************************************************
** Form generated from reading UI file 'flash_speed_ctrller_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FLASH_SPEED_CTRLLER_UI_H
#define FLASH_SPEED_CTRLLER_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpeedCtrllerWindow
{
public:
    QWidget *centralwidget;
    QPushButton *change_speed_btn;
    QSlider *speed_horizontal_slider;
    QPushButton *reset_speed_btn;
    QDoubleSpinBox *speed_double_spin_box;
    QLabel *speed_ctrller_tips_label;

    void setupUi(QMainWindow *SpeedCtrllerWindow)
    {
        if (SpeedCtrllerWindow->objectName().isEmpty())
            SpeedCtrllerWindow->setObjectName(QString::fromUtf8("SpeedCtrllerWindow"));
        SpeedCtrllerWindow->resize(300, 80);
        centralwidget = new QWidget(SpeedCtrllerWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        change_speed_btn = new QPushButton(centralwidget);
        change_speed_btn->setObjectName(QString::fromUtf8("change_speed_btn"));
        change_speed_btn->setGeometry(QRect(182, 53, 55, 23));
        speed_horizontal_slider = new QSlider(centralwidget);
        speed_horizontal_slider->setObjectName(QString::fromUtf8("speed_horizontal_slider"));
        speed_horizontal_slider->setGeometry(QRect(17, 20, 200, 16));
        speed_horizontal_slider->setMinimum(-16);
        speed_horizontal_slider->setMaximum(16);
        speed_horizontal_slider->setSingleStep(1);
        speed_horizontal_slider->setPageStep(1);
        speed_horizontal_slider->setValue(2);
        speed_horizontal_slider->setOrientation(Qt::Horizontal);
        reset_speed_btn = new QPushButton(centralwidget);
        reset_speed_btn->setObjectName(QString::fromUtf8("reset_speed_btn"));
        reset_speed_btn->setGeometry(QRect(240, 53, 55, 23));
        speed_double_spin_box = new QDoubleSpinBox(centralwidget);
        speed_double_spin_box->setObjectName(QString::fromUtf8("speed_double_spin_box"));
        speed_double_spin_box->setGeometry(QRect(227, 16, 62, 22));
        speed_double_spin_box->setMinimum(-16.000000000000000);
        speed_double_spin_box->setMaximum(16.000000000000000);
        speed_double_spin_box->setSingleStep(0.256000000000000);
        speed_double_spin_box->setValue(2.000000000000000);
        speed_ctrller_tips_label = new QLabel(centralwidget);
        speed_ctrller_tips_label->setObjectName(QString::fromUtf8("speed_ctrller_tips_label"));
        speed_ctrller_tips_label->setGeometry(QRect(5, 60, 141, 16));
        SpeedCtrllerWindow->setCentralWidget(centralwidget);

        retranslateUi(SpeedCtrllerWindow);

        QMetaObject::connectSlotsByName(SpeedCtrllerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SpeedCtrllerWindow)
    {
        SpeedCtrllerWindow->setWindowTitle(QApplication::translate("SpeedCtrllerWindow", "\345\217\230\351\200\237\347\252\227\345\217\243", nullptr));
        change_speed_btn->setText(QApplication::translate("SpeedCtrllerWindow", "\347\241\256\345\256\232", nullptr));
        reset_speed_btn->setText(QApplication::translate("SpeedCtrllerWindow", "\346\201\242\345\244\215", nullptr));
        speed_ctrller_tips_label->setText(QApplication::translate("SpeedCtrllerWindow", "\345\217\257\344\275\277\347\224\250\342\206\221\342\206\223\342\206\220\342\206\222\350\277\233\350\241\214\350\260\203\346\225\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpeedCtrllerWindow: public Ui_SpeedCtrllerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FLASH_SPEED_CTRLLER_UI_H
