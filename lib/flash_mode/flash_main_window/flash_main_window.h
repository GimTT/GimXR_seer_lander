/***************************************************************************************************
                        Project                  :                  seer_lander
                        MCU                      :                  None
                        IDE                      :                  QT5(CMake+MSVC2017)
                        File                     :                  flash_main_window.h
                        Brief                    :                  flash游戏界面头文件
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
#ifndef FLASH_MAIN_WINDOW_H
#define FLASH_MAIN_WINDOW_H

#include <QMainWindow>
#include "flash_main_window_ui.h"
#include "../flash_speed_ctrller/flash_speed_ctrller.h"
#include "../../automatic_operation/dm_window/dm_window.h"

class FlashMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    FlashMainWindow(QWidget * parent = nullptr);
    ~FlashMainWindow();
    void menu_add_items(void);
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);

public slots:
    void menu_trigger(QAction* act);
    void setting_trigger(QAction* act);
    void resize_trigger(QAction* act);
    void auto_menu_trigger(QAction* act);
    void audio_mute(bool status);
    void game_refresh(void);
    void create_speed_ctrller(void);
    void move_window(float relative_pos_x, float relative_pos_y);

private:
    Ui::FlashLanderMainWindow * ui;
    FlashSpeedCtrller * speed_ctrller = nullptr;
    DMWindow * dm_window = nullptr;
    HWND flash_window_handle = nullptr;
};

#endif // FLASH_MAIN_WINDOW_H
