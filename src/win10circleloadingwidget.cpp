#include "win10circleloadingwidget.h"

Win10CircleLoadingWidget::Win10CircleLoadingWidget(QWidget *parent)
    : Win10HorizontalLoadingWidget(parent)
{

}

void Win10CircleLoadingWidget::updateFrameRects()
{
    int rectLength = width() < height() ? width() : height();
    qreal radius = rectLength / 2.0 - itemLength();
}

void Win10CircleLoadingWidget::updateFrame()
{
    setCurrentFrame(currentFrame()+1);
    if (currentFrame() >= totalCount()) {
        setCurrentFrame(0);
        if (stopLoading())
            stopAnimationTimer();
    }
    update();
}

void Win10CircleLoadingWidget::paintEvent(QPaintEvent *)
{

}
