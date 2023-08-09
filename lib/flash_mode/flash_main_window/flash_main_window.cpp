#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>
#include "flash_main_window.h"
#include "../../../lander_conf.h"
#include "../../audio_mute/mediamute.h"

FlashMainWindow::FlashMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FlashLanderMainWindow)
{
    ui -> setupUi(this);

    /*设置控件属性      BEGIN*/
    ui -> seer_flash_game_window_axWidget -> setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));   //注册组件ID
    ui -> seer_flash_game_window_axWidget -> setProperty("DisplayAlerts",false);                                        //不显示警告信息
    ui -> seer_flash_game_window_axWidget -> dynamicCall("Navigate(const QString&)", FLASH_MODE_URL);
    /*设置控件属性      END*/

    menu_add_items();
}

FlashMainWindow::~FlashMainWindow()
{

}

void FlashMainWindow::menu_add_items(void)
{
    ui -> menu -> addAction(QString::fromLocal8Bit("刷新"));
    ui -> menu -> addAction(QString::fromLocal8Bit("静音"))->setCheckable(true);
    ui -> menu -> addAction(QString::fromLocal8Bit("变速"));

    /*脚本选项      BEGIN*/
    QMenu * auto_menu = new QMenu();
    ui ->menu->addMenu(auto_menu);
    auto_menu ->setTitle(QString::fromLocal8Bit("刷新"));
    auto_menu ->addAction(QString::fromLocal8Bit("自定义脚本"));
    /*脚本选项      END*/

    /*链接选项回调      BEGIN*/
    connect(ui -> menu, SIGNAL(triggered(QAction*)), this, SLOT(menu_trigger(QAction*)));
    connect(auto_menu, SIGNAL(triggered(QAction*)), this, SLOT(auto_menu_trigger(QAction*)));
    /*链接选项回调     END*/
}

void FlashMainWindow::audio_mute(bool status)
{
    MediaMute Cmute;
    if(status == true)
    {
        Cmute.SetMute(true);
        qDebug() << "[FLASH_MAIN_WIN][1]audio mute!";
    }
    else if(status == false)
    {
        Cmute.SetMute(false);
        qDebug() << "[FLASH_MAIN_WIN][0]audio unmute!";
    }
}

void FlashMainWindow::game_refresh(void)
{
    ui -> seer_flash_game_window_axWidget -> dynamicCall("Navigate(const QString&)", FLASH_MODE_URL);
    qDebug() << "[FLASH_MAIN_WIN]ReLoad!";
}

void FlashMainWindow::create_speed_ctrller(void)
{
    speed_ctrller = new FlashSpeedCtrller();
    speed_ctrller -> show();
}

void FlashMainWindow::menu_trigger(QAction* act)
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

    else if(act->text() == QString::fromLocal8Bit("变速"))
    {
        create_speed_ctrller();
    }
}

void FlashMainWindow::auto_menu_trigger(QAction* act)
{
    if(act->text() == QString::fromLocal8Bit("自定义脚本"))
    {
        dm_window = new DMWindow();
        dm_window -> show();
    }
}

void FlashMainWindow::closeEvent(QCloseEvent *event)
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
        if (speed_ctrller)
        {
            speed_ctrller -> hide();
            speed_ctrller -> close();
        }
        if (dm_window)
        {
            dm_window -> hide();
            dm_window -> close();
        }
        event -> accept();
    }
}
