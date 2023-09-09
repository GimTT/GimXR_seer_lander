/***************************************************************************************************
                        Project                  :                  seer_lander
                        MCU                      :                  None
                        IDE                      :                  QT5(CMake+MSVC2017)
                        File                     :                  startup_options.h
                        Brief                    :                  启动界面部分头文件
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
#ifndef __STARTUP_OPTIONS_H__
#define __STARTUP_OPTIONS_H__

#include <QMainWindow>
#include "startup_options_ui.h"
#include "../h5_mode/h5_main_window/h5_main_window.h"
#include "../flash_mode/flash_main_window/flash_main_window.h"

class StartupOptions : public QMainWindow
{
    Q_OBJECT

public:
    StartupOptions(QWidget *parent = nullptr);
    ~StartupOptions();

public slots:
    void switch_h5_mode(void);                      //槽函数，打开h5窗口     
    void switch_flash_mode(void);                   //槽函数，打开flash窗口

private:
    Ui::StartupModeWindow * ui;                     //ui界面
    H5MainWindow * h5_window = nullptr;             //h5登陆器
    FlashMainWindow * flash_window = nullptr;       //flash登陆器
};

void raise_privilege(void);                          //提权

#endif // STARTUP_OPTIONS_H
