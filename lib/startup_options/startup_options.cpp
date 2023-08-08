#include "startup_options.h"
#include <stdio.h>

startup_options::startup_options(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartupModeWindow)
{
    ui -> setupUi(this);

    /*绑定回调    BEGIN*/
    connect(ui->h5_mode_btn, SIGNAL(clicked()), this, SLOT(switch_h5_mode()));
    connect(ui->flash_mode_btn, SIGNAL(clicked()), this, SLOT(switch_flash_mode()));
    /*绑定回调    END*/

}

startup_options::~startup_options()
{

}

void startup_options::switch_flash_mode(void)
{
    printf("--------------Switch to Flash mode!---------------\n");
    this->hide();
    flash_main_window_t.show();
}

void startup_options::switch_h5_mode(void)
{
    printf("----------------Switch to H5 mode!----------------\n");
    this->hide();
    h5_main_window_t.show();
}
