#include "loadingtestwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoadingTestWidget w;
    w.show();
    return a.exec();
}
