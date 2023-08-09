#ifndef H5_MAIN_WINDOW_H
#define H5_MAIN_WINDOW_H

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

public slots:
    void audio_mute();
    void game_refresh();

private:
    Ui::H5LanderMainWindow *ui;
    QWebEngineView * m_view;
};

#endif // H5_MAIN_WINDOW_H
