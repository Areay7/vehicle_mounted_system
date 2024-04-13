#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    mainWindow = new MainWindow(this); // 初始化 mainWindow
}

MainWidget::~MainWidget()
{
    delete ui;
    delete mainWindow; // 释放 mainWindow 内存
}

void MainWidget::on_btnOpenWeatherWindow_clicked()
{
    mainWindow->show(); // 点击按钮打开主窗口
    hide(); // 隐藏当前窗口
}


