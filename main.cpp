#include <QApplication>
#include "startup_options.h"

int main(int argc, char *argv[])
{
    SetProcessDPIAware();
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    raise_privilege();
    QApplication app(argc, argv);
    StartupOptions startup_options;
    startup_options.show();
    return app.exec();
}
