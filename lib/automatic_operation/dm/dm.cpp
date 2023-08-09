#include <qprocess.h>
#include <Windows.h>
#include <QDebug>
#include "dm.h"
#include "../../../lander_conf.h"

DM::DM()
{
    reg();
    handle_init();
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

void DM::handle_init(void)
{
    dm_handle = new QAxWidget();
    dm_handle -> setControl(QString::fromUtf8("{26037A0E-7CBD-4FFF-9C63-56F2D0770214}"));
    qDebug() << "[DM_HANDLE]init read version: " + dm_handle -> dynamicCall("Ver()").toString();
}

void DM::bind_window(uint64_t pid)
{
    QString func_describe = "BindWindow(" + QString::number(pid) + "\"dx2\", \"windows\", \"windows\", 1)";
    dm_handle -> dynamicCall(func_describe.toStdString().c_str());
    qDebug() << "[DM_HANDLE]bind window func call: " << func_describe;
}

