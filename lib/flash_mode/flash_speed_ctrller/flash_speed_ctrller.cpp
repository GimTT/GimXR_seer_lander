/***************************************************************************************************
                        Project                  :                  seer_lander
                        MCU                      :                  None
                        IDE                      :                  QT5(CMake+MSVC2017)
                        File                     :                  flash_speed_ctrller.cpp
                        Brief                    :                  flash变速控制cpp文件
                        Developer                :                  金欣嵘
                        Other                    :                  
====================================================================================================

====================================================================================================
                                              History
====================================================================================================
----------------------------------------------------------------------------------------------------
                                            Brief 补充注释
----------------------------------------------------------------------------------------------------
                        Branch                   :                  dev_h5_lander_mode
                        Commit                   :                  eebfe18f3
----------------------------------------------------------------------------------------------------
***************************************************************************************************/
#include <QDebug>
#include <QDesktopWidget>
#include "../../../lander_conf.h"
#include "flash_speed_ctrller.h"

FlashSpeedCtrller::FlashSpeedCtrller(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpeedCtrllerWindow)
{
    /*注册dll       BEGIN*/
    speed_ctrl_handle = LoadLibrary(SPEED_CTRLLER_DLL_PATH);
    speed_set_range = (speed_set_range_t)GetProcAddress(speed_ctrl_handle, "SetRange");
    /*注册dll       END*/

    ui -> setupUi(this);
    move_window(SPEED_CTRLLER_WINDOW_RESET_POS_X, SPEED_CTRLLER_WINDOW_RESET_POS_Y);

    /*链接信号      BEGIN*/
    connect(ui -> speed_horizontal_slider, SIGNAL(valueChanged(int)), this, SLOT(get_speed_from_slider(int)));
    connect(ui -> speed_double_spin_box, SIGNAL(valueChanged(double)), this, SLOT(get_speed_from_spin_box(double)));
    connect(ui -> reset_speed_btn, SIGNAL(clicked()), this, SLOT(reset_speed_value()));
    connect(ui -> change_speed_btn, SIGNAL(clicked()), this, SLOT(set_speed_value()));
    /*链接信号      END*/
}

FlashSpeedCtrller::~FlashSpeedCtrller()
{
    
}

void FlashSpeedCtrller::move_window(float relative_pos_x, float relative_pos_y)
{
    QRect screen_rect = QApplication::desktop()->screenGeometry();
    int screen_width = screen_rect.width();
    int screen_height = screen_rect.height();
    this -> move((screen_width * relative_pos_x) - (this -> width() / 2), (screen_height * relative_pos_y) - (this -> height() / 2));
}

void FlashSpeedCtrller::get_speed_from_slider(int value)
{
    ui -> speed_double_spin_box->setValue(value);
    qDebug() << "[FLASH_SPEED_CTRLLER][slider]value changed -> " << value;
}

void FlashSpeedCtrller::get_speed_from_spin_box(double value)
{
    ui -> speed_horizontal_slider->setValue(static_cast<int>(value));
    qDebug() << "[FLASH_SPEED_CTRLLER][spin box]value changed -> " << value;
}

void FlashSpeedCtrller::dll_set_speed_callback(float value)
{
    speed_set_range(static_cast<float>(value));
    qDebug() << "[FLASH_SPEED_CTRLLER][dll call]value changed -> " << value;
}

void FlashSpeedCtrller::reset_speed_value(void)
{
    ui -> speed_double_spin_box -> setValue(static_cast<double>(SPEED_VALUE_RESET));
    ui -> speed_horizontal_slider -> setValue(static_cast<int>(SPEED_VALUE_RESET));
    dll_set_speed_callback(static_cast<float>(SPEED_VALUE_RESET));
}

void FlashSpeedCtrller::set_speed_value(void)
{
    ui -> speed_double_spin_box -> setValue(static_cast<double>(ui -> speed_double_spin_box -> value()));
    ui -> speed_horizontal_slider -> setValue(static_cast<int>(ui -> speed_horizontal_slider -> value()));
    dll_set_speed_callback(static_cast<float>(ui -> speed_double_spin_box -> value()));
}
