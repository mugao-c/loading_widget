#include "loadingtestwidget.h"
#include "ui_loadingtestwidget.h"

LoadingTestWidget::LoadingTestWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoadingTestWidget)
{
    ui->setupUi(this);
}

LoadingTestWidget::~LoadingTestWidget()
{
    delete ui;
}

