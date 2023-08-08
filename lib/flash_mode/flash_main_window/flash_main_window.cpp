#include "flash_main_window.h"
#include <stdio.h>
#include "../../audio_mute/mediamute.h"

#if TEST_MODE
    #define FLASH_MODE_URL ("http://www.baidu.com/")
#else
    #define FLASH_MODE_URL ("http://seer.61.com/play.shtml")
#endif

flash_main_window::flash_main_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FlashLanderMainWindow)
{
    ui->setupUi(this);
    ui->seer_flash_game_window_axWidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));//注册组件ID
    ui->seer_flash_game_window_axWidget->setProperty("DisplayAlerts",false);//不显示警告信息
    ui->seer_flash_game_window_axWidget->dynamicCall("Navigate(const QString&)", FLASH_MODE_URL);

    connect(ui -> audio_mute_checkBox, SIGNAL(clicked()), this, SLOT(audio_mute()));
    //connect(ui -> , SIGNAL(clicked()), this, SLOT(game_refresh()));
}

flash_main_window::~flash_main_window()
{
    
}


void flash_main_window::audio_mute()
{
    MediaMute Cmute;
    bool audio_status = ui -> audio_mute_checkBox -> isChecked();
    if(audio_status == true)
    {
        Cmute.SetMute(true);
    }
    else if(audio_status == false)
    {
        Cmute.SetMute(false);
    }
}

void flash_main_window::game_refresh()
{
    ui->seer_flash_game_window_axWidget->dynamicCall("Navigate(const QString&)", "http://seer.61.com/play.shtml");
}
