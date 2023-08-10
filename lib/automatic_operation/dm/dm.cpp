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
    QProcess process(0);
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

void DM::bind_window(uint32_t pid)
{
    QString func_describe = "BindWindow(" + QString::number(pid) + ", \"dx2\", \"windows\", \"windows\", 1)";
    dm_handle -> dynamicCall(func_describe.toStdString().c_str());
    qDebug() << "[DM_HANDLE]bind window func call: " << func_describe;
}

