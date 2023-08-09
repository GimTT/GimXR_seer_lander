#include <QDebug>
#include <QDesktopWidget>
#include "flash_speed_ctrller.h"

FlashSpeedCtrller::FlashSpeedCtrller(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpeedCtrllerWindow)
{
    speed_ctrl_handle = LoadLibrary("SpeedControl.dll");
    qDebug() << speed_ctrl_handle;
    speed_set_range = (speed_set_range_t)GetProcAddress(speed_ctrl_handle, "SetRange");
    qDebug() << speed_set_range;

    ui->setupUi(this);

    connect(ui -> speed_horizontal_slider, SIGNAL(valueChanged(int)), this, SLOT(get_speed_from_slider(int)));
    connect(ui -> speed_double_spin_box, SIGNAL(valueChanged(double)), this, SLOT(get_speed_from_spin_box(double)));
    connect(ui ->reset_speed_btn, SIGNAL(clicked()), this, SLOT(reset_speed_value()));
    connect(ui -> change_speed_btn, SIGNAL(clicked()), this, SLOT(set_speed_value()));
    move_window(0.5, 0.8);
}

FlashSpeedCtrller::~FlashSpeedCtrller()
{
    
}

void FlashSpeedCtrller::move_window(float relative_pos_x, float relative_pos_y)
{
    QRect screen_rect = QApplication::desktop()->screenGeometry();
    int screen_width = screen_rect.width();
    int screen_height = screen_rect.height();
    this -> move((screen_width * relative_pos_x) - (this->width() / 2), (screen_height * relative_pos_y) - (this->height() / 2));
}

void FlashSpeedCtrller::get_speed_from_slider(int value)
{
    ui ->speed_double_spin_box->setValue(value);
    qDebug() << "[FLASH_SPEED_CTRLLER][slider]value changed -> " << value;
}

void FlashSpeedCtrller::get_speed_from_spin_box(double value)
{
    ui ->speed_horizontal_slider->setValue((int)value);
    qDebug() << "[FLASH_SPEED_CTRLLER][spin box]value changed -> " << value;
}

void FlashSpeedCtrller::dll_set_speed_callback(float value)
{
    speed_set_range((float)value);
    qDebug() << "[FLASH_SPEED_CTRLLER][dll call]value changed -> " << value;
}

void FlashSpeedCtrller::reset_speed_value(void)
{
    ui ->speed_double_spin_box->setValue((double)1);
    ui ->speed_horizontal_slider->setValue((int)1);
    dll_set_speed_callback((float)1);
}

void FlashSpeedCtrller::set_speed_value(void)
{
    ui ->speed_double_spin_box -> setValue((double)ui -> speed_double_spin_box -> value());
    ui ->speed_horizontal_slider -> setValue((int)ui -> speed_horizontal_slider -> value());
    dll_set_speed_callback((float)ui -> speed_double_spin_box -> value());
}
