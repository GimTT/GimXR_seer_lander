#ifndef __DM_WINDOW_H__
#define __DM_WINDOW_H__

#include <QMainWindow>
#include <windows.h>
#include <stdint.h>
#include "dm_window_ui.h"
#include "../dm/dm.h"

#define DM_WINDOW_RESET_POS_X    0.5        //变速窗口初始化位置x（相对）
#define DM_WINDOW_RESET_POS_Y    0.1        //变速窗口初始化位置y（相对）

class DMWindow : public QMainWindow
{
    Q_OBJECT

public:
    DMWindow(QWidget * parent = nullptr);
    ~DMWindow();
    void move_window(float relative_pos_x, float relative_pos_y);

public slots:

private:
    Ui::DmWindow * ui;
    DM * dm;
};

#endif // __DM_WINDOW_H__
