#include "loadingtestwidget.h"
#include "../src/win10horizontalloadingwidget.h"
#include "../src/win10circleloadingwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win10CircleLoadingWidget w;
    w.resize(200,200);
    w.show();
    w.setItemLength(10);
    w.setExtendDuration(150);
    w.setItemCount(5);
    w.setDuration(1500);
    QList<QColor> colors;
    colors << QColor("#99CCCC") << QColor("#FFCC99")
           << QColor("#FFCCCC") << QColor("#CCCCFF")
           << QColor("#CC9999");
    w.setItemColors(colors);
    w.updateFrameData();
    w.start();
    return a.exec();
}
