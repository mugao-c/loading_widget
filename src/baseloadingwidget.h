#ifndef BASELOADINGWIDGET_H
#define BASELOADINGWIDGET_H

#include <QWidget>
#include <QEasingCurve>
#include <QTimer>

class BaseLoadingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseLoadingWidget(QWidget *parent = nullptr);
    void setEasingCurve(const QEasingCurve& curve); // 设置插值器
    void setFrameRate(const int& frameRate); // 设置帧率
    void setDuration(const int& duration); // 设置动画时长
    void setExtendDuration(const int& duration); // 设置追击动画时长

    void updateFrameData(); // 更新绘制帧数据

    bool isActive() { return  m_animationTimer->isActive(); } // 动画是否已经被激活

public slots:
    void start(); // 开始动画
    void stop(); // 结束动画
    void updateFrameRate(); // 更新动画刷新率，动画刷新率与屏幕刷新率一致

protected:
    inline QEasingCurve easingCurve() { return m_curve; }
    inline int frameCount() { return m_frameRects.count(); }
    inline qreal refreshTime() { return m_animationTimer->interval(); }
    inline int duration() { return m_duration; }
    inline int extendFrameCount() { return m_extendFrameCount; }
    // 获取某帧需要的绘制信息
    inline QRect frameRect(const int& index) {
        if (0 <= index && index <= m_frameRects.count())
            return m_frameRects.at(index);
        return QRect();
    }
    inline bool stopLoading() { return m_animationStop; }
    // 设置某帧的绘制信息
    inline void setFrameRect(const int& index,const QRect& rect) {
        if (0 <= index && index < m_frameRects.count())
            m_frameRects[index] = rect;
    }
    // 停止计时器
    inline void stopAnimationTimer() {
        m_animationTimer->stop();
        emit loaddingStoped();
    }
    // 获取某一帧时的值
    inline qreal frameValue(const int& index) {
        if (0 <= index && index < m_frameValues.count()) {
            return m_frameValues.at(index);
        }
        return 0;
    }
    // 计算每帧需要的绘制信息,在调用updateFrameData后会触发此函数
    virtual void updateFrameRects() = 0;
    // 刷新帧，即每次刷新帧都会调用此函数
    virtual void updateFrame() = 0;

signals:
    void loaddingStoped(); // 加载动画已经停止

private:
    void updateFrameValues();

private:
    QEasingCurve m_curve; // 插值器
    QList<QRect> m_frameRects; // 每一帧需要的rect数据
    QTimer* m_animationTimer; // 用于控制动画的计时器
    int m_frameRate; // 帧率
    int m_duration; // 完成一次动画需要的时间
    int m_extendDuration; // 追击延迟时间
    int m_extendFrameCount; // 追击帧数
    bool m_animationStop; // 是否停止动画
    QList<qreal> m_frameValues; // 每一帧对应的数值
};

#endif // BASELOADINGWIDGET_H
