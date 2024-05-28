#include "remoteview.h"
#include "ui_remoteview.h"

// 主窗口
RemoteViewWindow::RemoteViewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RemoteViewWindow)
{
    this->setFixedSize(1200, 600); // 设置窗体固定大小
    // setWindowFlag(Qt::FramelessWindowHint); // 设置窗口无边框

    ui->setupUi(this);
    socket = nullptr;

    //树莓派摄像头远程监控
    view = new QWebEngineView(this);
    //    view->load(QUrl("http://nps.areay7.cn:8099/")); //访问html配置文件
    // view->load(QUrl("http://8.130.79.179:8099/")); //访问html配置文件
    // view->load(QUrl("http://8.130.79.179:8095/")); //访问html配置文件
    // view->load(QUrl("https://mirrors.tuna.tsinghua.edu.cn/centos/2/")); //访问html配置文件

    view->load(QUrl("http://8.130.79.179:8101/")); //访问html配置文件
    view->resize(1195,595);  //设置控件界面大小


    view->show();


}

RemoteViewWindow::~RemoteViewWindow()
{
    delete ui;
}



void RemoteViewWindow::resizeEvent(QResizeEvent *)   //设置视频显示随窗口大小自动变化
{
    //    view->resize(this->size());
}





