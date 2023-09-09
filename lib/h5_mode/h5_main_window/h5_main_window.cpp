/***************************************************************************************************
                        Project                  :                  seer_lander
                        MCU                      :                  None
                        IDE                      :                  QT5(CMake+MSVC2017)
                        File                     :                  h5_main_window.cpp
                        Brief                    :                  H5游戏界面cpp文件
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
#include <QCloseEvent>
#include <QMessageBox>
#include "h5_main_window.h"
#include "../../../lander_conf.h"
#include "../../audio_mute/mediamute.h"

H5MainWindow::H5MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::H5LanderMainWindow)
{
    ui -> setupUi(this);
    ui -> seer_h5_view -> load(QUrl(H5_MODE_URL));
    menu_add_items();
}

H5MainWindow::~H5MainWindow()
{

}

void H5MainWindow::menu_add_items(void)
{
    ui -> menu -> addAction(QString::fromLocal8Bit("刷新"));
    ui -> menu -> addAction(QString::fromLocal8Bit("静音")) -> setCheckable(true);

    /*链接选项回调      BEGIN*/
    connect(ui -> menu, SIGNAL(triggered(QAction*)), this, SLOT(menu_trigger(QAction*)));
    /*链接选项回调      END*/
}

void H5MainWindow::audio_mute(bool status)
{
    MediaMute Cmute;
    if(status == true)
    {
        Cmute.SetMute(true);
        qDebug() << ("[FLASH_MAIN_WIN][1]audio mute!");
    }
    else if(status == false)
    {
        Cmute.SetMute(false);
        qDebug() << ("[FLASH_MAIN_WIN][0]audio unmute!");
    }
}

void H5MainWindow::game_refresh()
{
    ui -> seer_h5_view -> reload();
    qDebug() << ("[H5_MAIN_WIN]ReLoad!");
}

void H5MainWindow::menu_trigger(QAction* act)
{
    if(act->text() == QString::fromLocal8Bit("刷新"))
    {
        game_refresh();
    }

    else if(act->text() == QString::fromLocal8Bit("静音"))
    {
        if (act->isChecked())
        {
            audio_mute(true);
        }
        else
        {
            audio_mute(false);
        }
    }
}

void H5MainWindow::closeEvent(QCloseEvent *event)
{
    int result = QMessageBox::information(this,QString::fromLocal8Bit("系统提示"),\
                                         QString::fromLocal8Bit("是否关闭登录器?"),\
                                                    QString::fromLocal8Bit("是"),\
                                                    QString::fromLocal8Bit("否"),\
                                                    0, 1);
    if(result)
    {
        event -> ignore();
    }

    else
    {
        deleteLater();
        ui -> seer_h5_view -> close();
        event -> accept();
    }
}

void H5MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug() << "window size:" << event->size();
    ui ->centralwidget->resize(event->size());
    ui ->seer_h5_view->resize(event->size());
}
