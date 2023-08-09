#include <QApplication>
#include "startup_options.h"

int main(int argc, char *argv[])
{
    raisePrivilege();
    QApplication app(argc, argv);
    StartupOptions startup_options;
    startup_options.show();
    return app.exec();
}
