#include <QLibrary>
#include <qprocess.h>
#include <qmessagebox.h>
#include <Windows.h>
#include <QCoreApplication>
#include <QDebug>
#include "dm.h"
#include "../../../lander_conf.h"

DM::DM()
{
    reg_dm();
    dm_handle_init();
}

DM::~DM()
{

}

void DM::reg_dm(void)
{
    QString path = DM_DLL_PATH;
    QString cmdStr = "Regsvr32 " + path;
    QProcess process(0);
    process.start("cmd", QStringList() << "/c" << cmdStr);
    process.waitForStarted();
    process.waitForFinished();
}

void DM::dm_handle_init(void)
{
    dm_handle = new QAxWidget();
    dm_handle -> setControl(QString::fromUtf8("{26037A0E-7CBD-4FFF-9C63-56F2D0770214}"));
    qDebug() << "[DM_HANDLE]init read version: " + dm_handle->dynamicCall("Ver()").toString();
}

