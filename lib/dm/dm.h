#ifndef __DM_H__
#define __DM_H__

#include <QMainWindow>
#include <windows.h>
#include <stdint.h>

#define EXTERN _declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

typedef int(* speed_set_range_t)(float);
typedef HMODULE speed_ctrl_handle_t;

#ifdef __cplusplus
}
#endif

class DM : public QMainWindow
{
    Q_OBJECT

public:
    DM(QWidget * parent = nullptr);
    ~DM();

public slots:

private:
    //Ui::SpeedCtrllerWindow * ui;
};

#endif // __DM_H__
