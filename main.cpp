#include <QApplication>
#include "startup_options.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartupOptions startup_options;
    startup_options.show();
    return a.exec();
}
