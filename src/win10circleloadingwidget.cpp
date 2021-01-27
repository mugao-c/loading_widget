#include "win10circleloadingwidget.h"
#include <qmath.h>
#include <QPainter>

Win10CircleLoadingWidget::Win10CircleLoadingWidget(QWidget *parent)
    : Win10HorizontalLoadingWidget(parent)
{
    setCurrentFrame(0);
}

void Win10CircleLoadingWidget::updateFrameRects()
{
    auto rectRadius = itemLength() / 2;
    int radius = (width() < height() ? width() : height()) / 2 - rectRadius;
    int cx = width() / 2;
    int cy = height() / 2;

    for (int i = 0; i < frameCount(); ++i) {
        qreal zeta = frameValue(i) *  2 * M_PI;
        int x =  cx - qSin(zeta) * radius;
        int y = cy + qCos(zeta) * radius;
        setFrameRect(i,QRect(x-rectRadius,y-rectRadius,itemLength(),itemLength()));
    }
    setTotalCount(frameCount()+extendFrameCount()*(itemCount()-1));
}

void Win10CircleLoadingWidget::updateFrame()
{
    setCurrentFrame(currentFrame()+1);
    if (currentFrame() >= totalCount()) {
        setCurrentFrame(0);
        if (stopLoading()) {
            stopAnimationTimer();
        }
    }
    update();
}

void Win10CircleLoadingWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    if (!parentWidget()) {
        painter.fillRect(rect(),QBrush(backgroundColor()));
    }
    if (isActive()) {
        auto colors = itemColors();
        for (int i = 0; i < colors.count(); ++i) {
            QPainterPath path;
            auto index = currentFrame() - extendFrameCount()*i;
            if (index < 0 || index >= frameCount())
                continue;
            path.addEllipse(frameRect(index));
            painter.fillPath(path,QBrush(colors.at(i)));
        }
    }
}
