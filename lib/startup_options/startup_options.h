#ifndef STARTUP_OPTIONS_H
#define STARTUP_OPTIONS_H

#include <QMainWindow>
#include "startup_options_ui.h"
#include "../h5_mode/h5_main_window/h5_main_window.h"
#include "../flash_mode/flash_main_window/flash_main_window.h"

class StartupOptions : public QMainWindow
{
    Q_OBJECT

public:
    StartupOptions(QWidget *parent = nullptr);
    ~StartupOptions();
public slots:
    void switch_h5_mode(void);
    void switch_flash_mode(void);
private:
    Ui::StartupModeWindow *ui;
    H5MainWindow h5_window;            //h5登陆器
    FlashMainWindow flash_window;      //flash登陆器
};

#endif // STARTUP_OPTIONS_H
