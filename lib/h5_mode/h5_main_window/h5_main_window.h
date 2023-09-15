/***************************************************************************************************
                        Project                  :                  seer_lander
                        MCU                      :                  None
                        IDE                      :                  QT5(CMake+MSVC2017)
                        File                     :                  h5_main_window.h
                        Brief                    :                  H5游戏界面头文件
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
#ifndef __H5_MAIN_WINDOW_H__
#define __H5_MAIN_WINDOW_H__

#include <QMainWindow>
#include <QStackedLayout>
#include "h5_main_window_ui.h"
#include "../../automatic_operation/dm_window/dm_window.h"

class H5MainWindow : public QMainWindow, public Ui::H5LanderMainWindow
{
    Q_OBJECT

public:
    H5MainWindow(QWidget * parent = nullptr);
    ~H5MainWindow();
    void menu_add_items(void);
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void audio_mute(bool status);
    void game_refresh();
    void menu_trigger(QAction* act);
    void setting_trigger(QAction* act);

private:
    Ui::H5LanderMainWindow * ui;
    DMWindow * dm_window = nullptr;
    HWND h5_window_handle = nullptr;
    bool b_full_screen_flag = false;
};

#endif // H5_MAIN_WINDOW_H
