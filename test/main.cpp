#include "loadingtestwidget.h"
#include "../src/win10horizontalloadingwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win10HorizontalLoadingWidget w;
    w.resize(800,600);
    w.show();
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
