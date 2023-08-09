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
    this->hide();
    flash_window.show();
}

void StartupOptions::switch_h5_mode(void)
{
    qDebug() << ("----------------Switch to H5 mode!----------------");
    this->hide();
    h5_window.show();
}

void raisePrivilege(void)
{
    HANDLE hToken;
    TOKEN_PRIVILEGES tp;
    tp.PrivilegeCount = 1;
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    if(OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
    {
        if(LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid))
        {
            AdjustTokenPrivileges(hToken, FALSE, &tp, NULL, NULL, 0);
        }
    }
    if(hToken)
    {
        CloseHandle(hToken);
    }
}