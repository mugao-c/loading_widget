#include "win10horizontalloadingwidget.h"
#include <QPainter>
#include <QDebug>

Win10HorizontalLoadingWidget::Win10HorizontalLoadingWidget(QWidget *parent)
    : BaseLoadingWidget(parent)
{
    m_currentFrame = 0;
    setItemCount(1);
    setItemLength(10);
    setBackgroundColor(QColor(Qt::white));
    auto curve = QEasingCurve(QEasingCurve::BezierSpline);
    curve.addCubicBezierSegment(QPointF(0.31f, 0.85f),QPointF(0.77f, 0.14f),QPointF(1,1));
    setEasingCurve(curve);
    connect(this,SIGNAL(loaddingStoped()),SLOT(animationStoped()));
}

void Win10HorizontalLoadingWidget::setItemCount(const int &count)
{
    m_itemCount = count > 0 ? count : 1;
    m_itemColors.clear();
    for (int i = 0; i < count; ++i) {
        m_itemColors.append(QColor(Qt::black));
    }
}

void Win10HorizontalLoadingWidget::setItemColor(const int &index, const QColor &color)
{
    if (index < 0) {
        for (int i = 0; i < m_itemCount; ++i) {
            m_itemColors[i] = color;
        }
    } else if (index < m_itemCount){
        m_itemColors[index] = color;
    }
}

void Win10HorizontalLoadingWidget::setItemColors(const QList<QColor> &colors)
{
    for (int i = 0; i < colors.count(); ++i) {
        setItemColor(i,colors.at(i));
    }
}

void Win10HorizontalLoadingWidget::updateFrameRects()
{
    int w = m_itemLength;
    int y = (height()-w) / 2;
    for (int i = 0; i < frameCount(); ++i) {
        int x = frameValue(i)*width();
        setFrameRect(i,QRect(x,y,w,w));
    }
    m_totalCount = frameCount()+extendFrameCount()*(m_itemCount-1);
}

void Win10HorizontalLoadingWidget::updateFrame()
{
    m_currentFrame += 1;
    if (m_currentFrame >= m_totalCount) {
        m_currentFrame = 0;
        if (stopLoading()) {
            stopAnimationTimer();
        }
    }
    update();
}

void Win10HorizontalLoadingWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    if (!parentWidget()) {
        painter.fillRect(rect(),QBrush(m_bgColor));
    }
    if (isActive()) {
        for (int i = 0; i < m_itemColors.count(); ++i) {
            QPainterPath path;
            auto index = m_currentFrame - extendFrameCount()*i;
            if (index < 0 || index >= frameCount())
                continue;
            path.addEllipse(frameRect(index));
            painter.fillPath(path,QBrush(m_itemColors.at(i)));
        }
    }
}

void Win10HorizontalLoadingWidget::resizeEvent(QResizeEvent *)
{
    updateFrameData();
}

void Win10HorizontalLoadingWidget::animationStoped()
{
    m_currentFrame = 0;
}
