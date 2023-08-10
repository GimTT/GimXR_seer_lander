﻿/***************************************************************************************************
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
#include <QWebEngineView>
#include <QStackedLayout>
#include "h5_main_window_ui.h"

class H5MainWindow : public QMainWindow, public Ui::H5LanderMainWindow
{
    Q_OBJECT

public:
    H5MainWindow(QWidget * parent = nullptr);
    ~H5MainWindow();
    void menu_add_items(void);
    void closeEvent(QCloseEvent *event);

public slots:
    void audio_mute(bool status);
    void game_refresh();
    void menu_trigger(QAction* act);

private:
    Ui::H5LanderMainWindow *ui;
    QWebEngineView * seer_h5_view = nullptr;
};

#endif // H5_MAIN_WINDOW_H
