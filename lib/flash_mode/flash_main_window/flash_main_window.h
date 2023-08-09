#ifndef FLASH_MAIN_WINDOW_H
#define FLASH_MAIN_WINDOW_H

#include <QMainWindow>
#include "flash_main_window_ui.h"
#include "../flash_speed_ctrller/flash_speed_ctrller.h"

class FlashMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    FlashMainWindow(QWidget * parent = nullptr);
    ~FlashMainWindow();
    void menu_add_items(void);
    void closeEvent(QCloseEvent *event);

public slots:
    void menu_trigger(QAction* act);
    void audio_mute(bool status);
    void game_refresh(void);
    void create_speed_ctrller(void);

private:
    Ui::FlashLanderMainWindow * ui;
    FlashSpeedCtrller speed_ctrller;
};

#endif // FLASH_MAIN_WINDOW_H
