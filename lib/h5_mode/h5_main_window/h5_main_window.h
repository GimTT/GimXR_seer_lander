#ifndef __H5_MAIN_WINDOW_H__
#define __H5_MAIN_WINDOW_H__

#include <QMainWindow>
#include <QWebEngineView>
#include <QStackedLayout>
#include "h5_main_window_ui.h"

class H5MainWindow : public QMainWindow, public Ui::H5LanderMainWindow
{
    Q_OBJECT

public:
    H5MainWindow(QWidget * parent = nullptr);
    ~H5MainWindow();
    void menu_add_items(void);
    void closeEvent(QCloseEvent *event);

public slots:
    void audio_mute(bool status);
    void game_refresh();
    void menu_trigger(QAction* act);

private:
    Ui::H5LanderMainWindow *ui;
    QWebEngineView * seer_h5_view = nullptr;
};

#endif // H5_MAIN_WINDOW_H
