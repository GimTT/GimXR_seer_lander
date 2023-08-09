#ifndef FLASH_SPEED_CTRLLER_H
#define FLASH_SPEED_CTRLLER_H

#include <QMainWindow>
#include <windows.h>
#include <stdint.h>
#include "flash_speed_ctrller_ui.h"

#define EXTERN _declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

typedef int(* speed_set_range_t)(float);
typedef HMODULE speed_ctrl_handle_t;

#ifdef __cplusplus
}
#endif

class FlashSpeedCtrller : public QMainWindow
{
    Q_OBJECT

public:
    speed_ctrl_handle_t speed_ctrl_handle;
    speed_set_range_t speed_set_range;
    FlashSpeedCtrller(QWidget * parent = nullptr);
    ~FlashSpeedCtrller();
    void move_window(float relative_pos_x, float relative_pos_y);
    void dll_set_speed_callback(float value);

public slots:
    void get_speed_from_slider(int value);
    void get_speed_from_spin_box(double value);
    void reset_speed_value(void);
    void set_speed_value(void);

private:
    Ui::SpeedCtrllerWindow * ui;
};

#endif // FLASH_MAIN_WINDOW_H
