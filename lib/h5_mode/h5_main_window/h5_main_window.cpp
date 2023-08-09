#include <QDebug>
#include "h5_main_window.h"
#include "../../audio_mute/mediamute.h"

#if TEST_MODE
    #define H5_MODE_URL ("http://www.baidu.com/")
#else
    #define H5_MODE_URL ("http://seerh5.61.com/")
#endif

H5MainWindow::H5MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::H5LanderMainWindow)
{
    ui -> setupUi(this);
    m_view = new QWebEngineView(this);
    QStackedLayout * layout = new QStackedLayout(ui -> seer_h5_game_window_frame);
    ui -> seer_h5_game_window_frame -> setLayout(layout);
    layout -> addWidget(m_view);
    m_view -> load(QUrl(H5_MODE_URL));
    connect(ui -> audio_mute_checkBox, SIGNAL(clicked()), this, SLOT(audio_mute()));
    connect(ui -> refresh_btn, SIGNAL(clicked()), this, SLOT(game_refresh()));
}

H5MainWindow::~H5MainWindow()
{

}


void H5MainWindow::audio_mute()
{
    MediaMute Cmute;
    bool audio_status = ui -> audio_mute_checkBox -> isChecked();
    if(audio_status == true)
    {
        Cmute.SetMute(true);
    }
    else if(audio_status == false)
    {
        Cmute.SetMute(false);
    }
}

void H5MainWindow::game_refresh()
{
    m_view -> reload();
    qDebug() << ("[H5_MAIN_WIN]ReLoad!");
}
