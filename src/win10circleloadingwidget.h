#ifndef WIN10CIRCLELOADINGWIDGET_H
#define WIN10CIRCLELOADINGWIDGET_H

#include "win10horizontalloadingwidget.h"

class Win10CircleLoadingWidget : public Win10HorizontalLoadingWidget
{
    Q_OBJECT
public:
    explicit Win10CircleLoadingWidget(QWidget *parent = nullptr);

protected:
    virtual void updateFrameRects() override;
    virtual void paintEvent(QPaintEvent *) override;

signals:

};

#endif // WIN10CIRCLELOADINGWIDGET_H
