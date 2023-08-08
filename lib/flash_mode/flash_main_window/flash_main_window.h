#ifndef FLASH_MAIN_WINDOW_H
#define FLASH_MAIN_WINDOW_H

#include <QMainWindow>
#include "flash_main_window_ui.h"

class flash_main_window : public QMainWindow
{
    Q_OBJECT

public:
    flash_main_window(QWidget * parent = nullptr);
    ~flash_main_window();

public slots:
    void audio_mute();
    void game_refresh();

private:
    Ui::FlashLanderMainWindow *ui;
};

#endif // FLASH_MAIN_WINDOW_H
