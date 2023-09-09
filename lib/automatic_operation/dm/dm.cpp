/***************************************************************************************************
                        Project                  :                  seer_lander
                        MCU                      :                  None
                        IDE                      :                  QT5(CMake+MSVC2017)
                        File                     :                  dm.cpp
                        Brief                    :                  大漠插件基cpp文件
                        Developer                :                  金欣嵘
                        Other                    :                  
====================================================================================================

====================================================================================================
                                              History
====================================================================================================
----------------------------------------------------------------------------------------------------
                                            Brief 补充注释
----------------------------------------------------------------------------------------------------
                        Branch                   :                  dev_h5_lander_mode
                        Commit                   :                  eebfe18f3
----------------------------------------------------------------------------------------------------
***************************************************************************************************/
#include <qprocess.h>
#include <Windows.h>
#include <QDebug>
#include "dm.h"
#include "../../../lander_conf.h"

DM::DM()
{
    if (QString::compare(handle_init(), "3.1233"))
    {
        reg();
        handle_init();
    }
    else
    {
        qDebug() << "[DM_HANDLE]dm dll is inited";
    }
}

DM::~DM()
{

}

void DM::reg(void)
{
    QString path = DM_DLL_PATH;
    QString cmdStr = "Regsvr32 " + path;
    QProcess process(nullptr);
    process.start("cmd", QStringList() << "/c" << cmdStr);
    process.waitForStarted();
    process.waitForFinished();
}

QString DM::handle_init(void)
{
    QString version;
    dm_handle = new QAxWidget();
    dm_handle -> setControl(QString::fromUtf8("{26037A0E-7CBD-4FFF-9C63-56F2D0770214}"));
    version = dm_handle -> dynamicCall("Ver()").toString();
    qDebug() << "[DM_HANDLE]init read version: " + version;
    return version;
}

pic_info_t DM::find_pic(int x1, int y1, int x2, int y2, QString pic_name, QString delta_color, double sim, int dir)
{
    pic_info_t pic_info;
    QString ret_val;
    QString func_describe = "FindPicE(" + QString::number(x1) + ","\
                                        + QString::number(y1) + ","\
                                        + QString::number(x2) + ","\
                                        + QString::number(y2) + ","\
                                        + "\"" + pic_name + "\"" + ","\
                                        + "\"" + delta_color + "\"" + ","\
                                        + QString::number(sim) + ","\
                                        + QString::number(dir) + ")";
    ret_val = dm_handle -> dynamicCall(func_describe.toStdString().c_str()).toString();
    qDebug() << "[DM_HANDLE]bind window func call: " << func_describe << " retVal: " << ret_val;

    QStringList list = ret_val.split("|");
    pic_info.index = list[0].toInt();
    pic_info.x = list[1].toInt();
    pic_info.y = list[2].toInt();

    return pic_info;
}

void DM::bind_window(uint32_t pid)
{
    QString func_describe = "BindWindow(" + QString::number(pid) + ", \"dx2\", \"windows\", \"windows\", 1)";
    dm_handle -> dynamicCall(func_describe.toStdString().c_str()).toString();
    qDebug() << "[DM_HANDLE]bind window func call: " << func_describe;
}

