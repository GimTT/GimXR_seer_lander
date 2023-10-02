/***************************************************************************************************
                        Project                  :                  seer_lander
                        MCU                      :                  None
                        IDE                      :                  QT5(CMake+MSVC2017)
                        File                     :                  flash_main_window.cpp
                        Brief                    :                  flash游戏界面cpp文件
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
#include <QMessageBox>
#include <QCloseEvent>
#include <QTimer>
#include <QDesktopWidget>
#include "flash_main_window.h"
#include "../../../lander_conf.h"
#include "../../audio_mute/mediamute.h"
#include <windows.h>
#pragma comment (lib,"Gdi32.lib")
#pragma comment (lib,"User32.lib")


FlashMainWindow::FlashMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FlashLanderMainWindow)
{
    ui -> setupUi(this);
    srceen_scale = get_screen_scale();                                                                                  //获取缩放倍率

    /*设置控件属性      BEGIN*/
    ui -> seer_flash_game_window_axWidget -> setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));   //注册组件ID
    ui -> seer_flash_game_window_axWidget -> setProperty("DisplayAlerts", false);                                       //不显示警告信息
    ui -> seer_flash_game_window_axWidget -> setProperty("DisplayScrollBars", false);                                   //不显示滚动条
    ui -> seer_flash_game_window_axWidget -> dynamicCall("Navigate(const QString&)", FLASH_MODE_URL);
    /*设置控件属性      END*/

    this->setWindowFlags(this->windowFlags() &~ Qt::WindowMaximizeButtonHint);                      //禁止最大化

    flash_window_handle = (HWND)this -> ui -> seer_flash_game_window_axWidget -> winId();           //获取窗口句柄
    qDebug() << "[FLASH_MAIN_WIN][win handle]" << flash_window_handle;
    menu_add_items();

    /*创建定时器初始化时调整窗口大小   BEGIN*/
    QTimer * timer = new QTimer(this);
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        static int reset_cnt = 0;
        this->setFixedSize(static_cast<int>(960.0 * 1.0), static_cast<int>((560.0 * 1.0) + 22));
        scale_game_window(100);
        if (reset_cnt == 3)
        {
            timer->stop();
        }
        else
        {
            reset_cnt ++;
        }
    });
    /*创建定时器初始化时调整窗口大小   END*/

    this->setFocusPolicy(Qt::ClickFocus);
}

FlashMainWindow::~FlashMainWindow()
{

}

void FlashMainWindow::move_window(float relative_pos_x, float relative_pos_y)
{
    QRect screen_rect = QApplication::desktop()->normalGeometry();  //->screenGeometry();
    int screen_width = screen_rect.width();
    int screen_height = screen_rect.height();
    this -> move(static_cast<int>((screen_width * relative_pos_x) - (this -> width() / 2)), static_cast<int>((screen_height * relative_pos_y) - (this -> height() / 2)));
}

void FlashMainWindow::menu_add_items(void)
{
    /*菜单选项设置        BEGIN*/
    ui -> menu -> addAction(QString::fromLocal8Bit("刷新"));
    ui -> menu -> addAction(QString::fromLocal8Bit("静音"))->setCheckable(true);
    ui -> menu -> addAction(QString::fromLocal8Bit("变速"));

    /*脚本选项      BEGIN*/
    QMenu * auto_menu = new QMenu();
    ui ->menu->addMenu(auto_menu);
    auto_menu ->setTitle(QString::fromLocal8Bit("脚本"));
    auto_menu ->addAction(QString::fromLocal8Bit("自定义脚本"));
    /*脚本选项      END*/

    /*链接选项回调    BEGIN*/
    connect(ui -> menu, SIGNAL(triggered(QAction*)), this, SLOT(menu_trigger(QAction*)));
    connect(auto_menu, SIGNAL(triggered(QAction*)), this, SLOT(auto_menu_trigger(QAction*)));
    /*链接选项回调    END*/
    /*菜单选项设置        END*/

    /*设置选项设置        BEGIN*/
    /*缩放选项      BEGIN*/
    QMenu * resize_menu = new QMenu();
    ui -> setting -> addMenu(resize_menu);
    resize_menu -> setTitle(QString::fromLocal8Bit("缩放"));
    resize_menu -> addAction(QString::fromLocal8Bit("50%"));
    resize_menu -> addAction(QString::fromLocal8Bit("75%"));
    resize_menu -> addAction(QString::fromLocal8Bit("100%"));
    resize_menu -> addAction(QString::fromLocal8Bit("125%"));
    resize_menu -> addAction(QString::fromLocal8Bit("150%"));
    resize_menu -> addAction(QString::fromLocal8Bit("全屏"));
    /*缩放选项      END*/

    /*链接设置回调    BEGIN*/
    connect(ui -> setting, SIGNAL(triggered(QAction*)), this, SLOT(setting_trigger(QAction*)));
    connect(resize_menu, SIGNAL(triggered(QAction*)), this, SLOT(resize_trigger(QAction*)));
    /*链接设置回调    END*/
    /*设置选项设置        END*/
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

void FlashMainWindow::setting_trigger(QAction* act)
{

}


void FlashMainWindow::auto_menu_trigger(QAction* act)
{
    if(act->text() == QString::fromLocal8Bit("自定义脚本"))
    {
        dm_window = new DMWindow(nullptr, flash_window_handle, flash_mode);
        dm_window -> show();
        dm_window -> dm -> find_pic(0, 0, this -> width(), this -> height(), "test.bmp", "000000", 0.8, 0);
    }
}

void FlashMainWindow::resize_trigger(QAction* act)
{
    if(act->text() == QString::fromLocal8Bit("50%"))
    {
        this->setFixedSize(static_cast<int>(960.0 * 0.5), (static_cast<int>(560.0 * 0.5) + 22));
        scale_game_window(50);
    }
    else if (act->text() == QString::fromLocal8Bit("75%"))
    {
        this->setFixedSize(static_cast<int>(960.0 * 0.75), static_cast<int>((560.0 * 0.75) + 22));
        scale_game_window(75);
    }
    else if (act->text() == QString::fromLocal8Bit("100%"))
    {
        this->setFixedSize(static_cast<int>(960.0 * 1.0), static_cast<int>((560.0 * 1.0) + 22));
        scale_game_window(100);
    }
    else if (act->text() == QString::fromLocal8Bit("125%"))
    {
        this->setFixedSize(static_cast<int>(960.0 * 1.25), static_cast<int>((560.0 * 1.25) + 22));
        scale_game_window(125);
    }
    else if (act->text() == QString::fromLocal8Bit("150%"))
    {
        this->setFixedSize(static_cast<int>(960.0 * 1.50), static_cast<int>((560.0 * 1.50) + 22));
        scale_game_window(150);
    }
#if 0
    else if (act->text() == QString::fromLocal8Bit("全屏"))
    {
        int result = QMessageBox::information(this, QString::fromLocal8Bit("系统提示"),\
                                       QString::fromLocal8Bit("将开启全屏, 按F12退出。"),\
                                                    QString::fromLocal8Bit("确认"),\
                                                    QString::fromLocal8Bit("取消"),\
                                                    0, 1);
        if(result)
        {
            return;
        }
        b_full_screen_flag = true;
        showFullScreen();
        ui -> menuBar-> setVisible(false);
    }
#endif
    this->move_window(0.5, 0.5);
}

void FlashMainWindow::closeEvent(QCloseEvent *event)
{
    int result = QMessageBox::information(this,QString::fromLocal8Bit("系统提示"),\
                                         QString::fromLocal8Bit("是否关闭登录器?"),\
                                                    QString::fromLocal8Bit("是"),\
                                                    QString::fromLocal8Bit("否"));
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

void FlashMainWindow::resizeEvent(QResizeEvent * event)
{
    qDebug() << "window size:" << event->size();
    if (b_full_screen_flag)
    {
        ui -> centralwidget -> resize(this -> width(), this -> height());
        ui -> groupBox -> resize(this -> width(), this -> height());
        ui ->seer_flash_game_window_axWidget->resize(this -> width() + 20, this -> height() + 20);
    }
    else
    {
        ui -> centralwidget -> resize(this -> width(), (this -> height() - 22));
        ui -> groupBox -> resize(this -> width(), (this -> height() - 22));
        ui ->seer_flash_game_window_axWidget->resize(this -> width() + 20, (this -> height() - 22) + 20);
    }
}

double FlashMainWindow::get_screen_scale(void)
{
    HDC hd = GetDC(NULL);
    //int horDPI = GetDeviceCaps(hd, LOGPIXELSX);           //水平缩放倍数
    int verticalDPI = GetDeviceCaps(hd, LOGPIXELSY);        //垂直缩放倍数
    double srceen_scale = (double)verticalDPI /96.0;
    return srceen_scale;
}

void FlashMainWindow::scale_game_window(int zoom)
{
    zoom = static_cast<int>(zoom * srceen_scale * srceen_scale);
    ui-> seer_flash_game_window_axWidget -> dynamicCall(("ExecWB(OLECMDID_OPTICAL_ZOOM, OLECMDEXECOPT_DODEFAULT, " + QString::number(zoom) + ")").toStdString().c_str());
    qDebug() << "[FLASH_MAIN_WIN][zoom]dpi:" <<zoom;
    qDebug() << "[FLASH_MAIN_WIN][zoom]game window size:" << ui->seer_flash_game_window_axWidget->size();
}

