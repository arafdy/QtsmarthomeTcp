#include "smarthomedialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    smarthomeDialog w;
    w.show();

    return a.exec();
}
