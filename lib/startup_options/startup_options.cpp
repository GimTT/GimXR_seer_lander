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
