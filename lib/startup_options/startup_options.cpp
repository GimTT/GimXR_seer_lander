/***************************************************************************************************
                        Project                  :                  seer_lander
                        MCU                      :                  None
                        IDE                      :                  QT5(CMake+MSVC2017)
                        File                     :                  startup_options.cpp
                        Brief                    :                  启动界面部分cpp文件
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
#include "startup_options.h"

StartupOptions::StartupOptions(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartupModeWindow)
{
    ui -> setupUi(this);

    /*绑定回调    BEGIN*/
    connect(ui -> h5_mode_btn, SIGNAL(clicked()), this, SLOT(switch_h5_mode()));
    connect(ui -> flash_mode_btn, SIGNAL(clicked()), this, SLOT(switch_flash_mode()));
    /*绑定回调    END*/

}

StartupOptions::~StartupOptions()
{

}

void StartupOptions::switch_flash_mode(void)
{
    qDebug() << ("--------------Switch to Flash mode!---------------");
    flash_window = new FlashMainWindow();
    flash_window->show();
    this->hide();
}

void StartupOptions::switch_h5_mode(void)
{
    qDebug() << ("----------------Switch to H5 mode!----------------");
    h5_window = new H5MainWindow();
    h5_window->show();
    this->hide();
}

/***************************************************************************************************
*   Name   :   raise_privilege
*  Input   :   NULL
*  Output  :   NULL
*  RetVal  :   NULL
* Function :   提权函数
***************************************************************************************************/
void raise_privilege(void)
{
    HANDLE hToken;
    TOKEN_PRIVILEGES tp;
    tp.PrivilegeCount = 1;
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    if(OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
    {
        if(LookupPrivilegeValue(nullptr, SE_DEBUG_NAME, &tp.Privileges[0].Luid))
        {
            AdjustTokenPrivileges(hToken, FALSE, &tp, NULL, NULL, nullptr);
        }
    }
    if(hToken)
    {
        CloseHandle(hToken);
    }
}
