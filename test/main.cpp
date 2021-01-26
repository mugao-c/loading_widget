#include "loadingtestwidget.h"
#include "../src/win10horizontalloadingwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win10HorizontalLoadingWidget w;
    w.resize(800,600);
    w.show();
    w.setItemLength(10);
    w.setItemCount(5);
    w.setDuration(1500);
    w.updateFrameData();
    w.start();
    return a.exec();
}
