#include "mainwidget.h"
#include "currentsituation.h"
#include "ui_mainwidget.h"
#include "controlwidget.h"
#include <QPixmap>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{

    ui->setupUi(this);
    // 使用 QIcon 加载图像文件
    QIcon icon(":/res/xiaomisu7.jpg");

    // 将 QIcon 转换为 QPixmap
    QPixmap pixmap = icon.pixmap(QSize(670, 500)); // 设置图像大小，如果需要的话

    // 设置图像到 QLabel
    ui->label->setPixmap(pixmap);



    mainWindow = new MainWindow(this); // 分配内存给 mainWindow 指针
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_btnOpenWeatherWindow_clicked()
{
    mainWindow->show(); // 显示主窗口
    hide(); // 隐藏当前窗口
}

void MainWidget::on_btnOpenSituationWindow_clicked()
{
    // 创建 CurrentSituation 窗口对象
    CurrentSituation *situationWindow = new CurrentSituation();

    // 显示 CurrentSituation 窗口
    situationWindow->show();
    hide(); // 隐藏当前窗口
}





void MainWidget::on_btnOpenControlWindow_clicked()
{
    // 创建并显示 ControlWidget 窗口，并传递 MainWidget 对象的指针
    ControlWidget *controlWidget = new ControlWidget();


    controlWidget->show();
    hide();
}





