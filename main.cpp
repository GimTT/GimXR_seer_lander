#include "startup_options.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startup_options startup_options_t;
    startup_options_t.show();
    return a.exec();
}
