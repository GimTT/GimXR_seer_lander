/***************************************************************************************************
                        Project                  :                  seer_lander
                        MCU                      :                  None
                        IDE                      :                  QT5(CMake+MSVC2017)
                        File                     :                  flash_speed_ctrller.h
                        Brief                    :                  flash变速控制头文件
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
#ifndef __FLASH_SPEED_CTRLLER_H__
#define __FLASH_SPEED_CTRLLER_H__

#include <QMainWindow>
#include <windows.h>
#include <stdint.h>
#include "flash_speed_ctrller_ui.h"

#define EXTERN _declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

typedef int(* speed_set_range_t)(float);
typedef HMODULE speed_ctrl_handle_t;

#ifdef __cplusplus
}
#endif

#define SPEED_CTRLLER_WINDOW_RESET_POS_X    0.5     //变速窗口初始化位置x（相对）
#define SPEED_CTRLLER_WINDOW_RESET_POS_Y    0.8     //变速窗口初始化位置y（相对）
#define SPEED_VALUE_RESET                   1       //变速重置值

class FlashSpeedCtrller : public QMainWindow
{
    Q_OBJECT

public:
    speed_ctrl_handle_t speed_ctrl_handle;
    speed_set_range_t speed_set_range;
    FlashSpeedCtrller(QWidget * parent = nullptr);
    ~FlashSpeedCtrller();
    void move_window(float relative_pos_x, float relative_pos_y);
    void dll_set_speed_callback(float value);

public slots:
    void get_speed_from_slider(int value);
    void get_speed_from_spin_box(double value);
    void reset_speed_value(void);
    void set_speed_value(void);

private:
    Ui::SpeedCtrllerWindow * ui;
};

#endif // FLASH_MAIN_WINDOW_H
