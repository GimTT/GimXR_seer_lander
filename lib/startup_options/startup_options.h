#ifndef STARTUP_OPTIONS_H
#define STARTUP_OPTIONS_H

#include <QMainWindow>
#include "startup_options_ui.h"
#include "../h5_mode/h5_main_window/h5_main_window.h"
#include "../flash_mode/flash_main_window/flash_main_window.h"

class startup_options : public QMainWindow
{
    Q_OBJECT

public:
    startup_options(QWidget *parent = nullptr);
    ~startup_options();
public slots:
    void switch_h5_mode(void);
    void switch_flash_mode(void);
private:
    Ui::StartupModeWindow *ui;
    h5_main_window h5_main_window_t;    //h5登陆器
    flash_main_window flash_main_window_t;      //flash登陆器
};

#endif // STARTUP_OPTIONS_H
