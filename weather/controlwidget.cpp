#include "controlwidget.h"
#include "ui_controlwidget.h"

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlWidget)
{
    ui->setupUi(this);
    ui->label_28->setStyleSheet("color:#4aa2a7; border:none;");
    setWindowFlag(Qt::FramelessWindowHint); // 设置窗口无边框

}

ControlWidget::~ControlWidget()
{
    delete ui;
}
