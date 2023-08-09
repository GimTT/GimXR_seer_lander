#include <QDebug>
#include "h5_main_window.h"
#include "../../../lander_conf.h"
#include "../../audio_mute/mediamute.h"

H5MainWindow::H5MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::H5LanderMainWindow)
{
    ui -> setupUi(this);
    seer_h5_view = new QWebEngineView(this);
    QStackedLayout * layout = new QStackedLayout(ui -> seer_h5_game_window_frame);
    ui -> seer_h5_game_window_frame -> setLayout(layout);
    layout -> addWidget(seer_h5_view);
    seer_h5_view -> load(QUrl(H5_MODE_URL));

    menu_add_items();
}

H5MainWindow::~H5MainWindow()
{

}

void H5MainWindow::menu_add_items(void)
{
    ui -> menu -> addAction(QString::fromLocal8Bit("刷新"));
    ui -> menu -> addAction(QString::fromLocal8Bit("静音"))->setCheckable(true);

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
    seer_h5_view -> reload();
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