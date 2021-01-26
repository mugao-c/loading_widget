#ifndef LOADINGTESTWIDGET_H
#define LOADINGTESTWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LoadingTestWidget; }
QT_END_NAMESPACE

class LoadingTestWidget : public QWidget
{
    Q_OBJECT

public:
    LoadingTestWidget(QWidget *parent = nullptr);
    ~LoadingTestWidget();

private:
    Ui::LoadingTestWidget *ui;
};
#endif // LOADINGTESTWIDGET_H
