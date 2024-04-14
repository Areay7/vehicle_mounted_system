#include "mainwidget.h"
#include "currentsituation.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
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
    CurrentSituation *situationWindow = new CurrentSituation(this);

    // 显示 CurrentSituation 窗口
    situationWindow->show();
    hide(); // 隐藏当前窗口
}




