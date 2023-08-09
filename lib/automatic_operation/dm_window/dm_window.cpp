#include <QDebug>
#include <QDesktopWidget>
#include "../../../lander_conf.h"
#include "dm_window.h"

DMWindow::DMWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DmWindow)
{
    ui -> setupUi(this);

    /*大漠初始化     BEGIN*/
    dm = new DM();
    dm -> bind_window(0x12456);
    /*大漠初始化     END*/
    move_window(DM_WINDOW_RESET_POS_X, DM_WINDOW_RESET_POS_Y);
}

DMWindow::~DMWindow()
{
    
}

void DMWindow::move_window(float relative_pos_x, float relative_pos_y)
{
    QRect screen_rect = QApplication::desktop()->screenGeometry();
    int screen_width = screen_rect.width();
    int screen_height = screen_rect.height();
    this -> move((screen_width * relative_pos_x) - (this -> width() / 2), (screen_height * relative_pos_y) - (this -> height() / 2));
}

