#include "remotecontrol.h"
#include "ui_remotecontrol.h"

// 主窗口
RemoteWindow::RemoteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RemoteWindow)
{
    this->setFixedSize(1200, 600); // 设置窗体固定大小
    setWindowFlag(Qt::FramelessWindowHint); // 设置窗口无边框

    ui->setupUi(this);
    socket = nullptr;



    //树莓派摄像头远程监控
    view = new QWebEngineView(this);
    //    view->load(QUrl("http://nps.areay7.cn:8099/")); //访问html配置文件
    view->load(QUrl("http://8.130.79.179:8099/")); //访问html配置文件
    view->resize(800,600);  //设置控件界面大小
    view->show();


    // 构建右键菜单
    mExitMenu  = new QMenu(this);
    mExitAct = new QAction();
    mReturnAct = new QAction();

    mExitAct->setText("退出");
    mExitAct->setIcon(QIcon(":/res/close.png"));
    mReturnAct->setText("返回菜单"); // 添加返回动作文本
    mReturnAct->setIcon(QIcon(":/res/close.png")); // 添加返回动作图标

    // 将动作添加到右键菜单
    mExitMenu->addAction(mExitAct);
    mExitMenu->addAction(mReturnAct); // 将返回动作添加到右键菜单

    // 连接返回动作的信号和槽
    connect(mExitAct, &QAction::triggered, this, [=]{
        qApp->exit(0);
    });

    connect(mReturnAct, &QAction::triggered, this, [=]{
        // 隐藏当前窗口（即 MainWindow）
        hide();
        // 显示主窗口（即 MainWidget）
        parentWidget()->show();
    });
}

RemoteWindow::~RemoteWindow()
{
    delete ui;
}


// 重写父类虚函数
// 父类中默认的实现  是忽略右键菜单事件
// 重写之后，就可以处理右键菜单
void RemoteWindow::contextMenuEvent(QContextMenuEvent *event)
{
    // 弹出右键菜单
    mExitMenu->exec(QCursor::pos());

    event->accept();
}




void RemoteWindow::resizeEvent(QResizeEvent *)   //设置视频显示随窗口大小自动变化
{
    //    view->resize(this->size());
}


//==============================按键发送指令=================================

//前进按键按下
void RemoteWindow::on_pushButtonGoHead_pressed()
{
    if(NULL == socket)
    {
        ui->textEditInfomation->append("Please connect\n");
        this->close();
    }
    else
    {
        socket->write("U",1);  //发送指令
        ui->textEditInfomation->append("前进\n");
    }
}

//左转按键按下
void RemoteWindow::on_pushButtonTurnLeft_pressed()
{
    if(NULL == socket)
    {
        ui->textEditInfomation->append("Please connect\n");
        this->close();
    }
    else
    {
        socket->write("L",1);  //发送指令
        ui->textEditInfomation->append("左转\n");
    }
}


//后退按键按下
void RemoteWindow::on_pushButtonGoBack_pressed()
{
    if(NULL == socket)
    {
        ui->textEditInfomation->append("Please connect\n");
        this->close();
    }
    else
    {
        socket->write("D",1);  //发送指令
        ui->textEditInfomation->append("后退\n");
    }
}

//右转按键按下
void RemoteWindow::on_pushButtonTurnRight_pressed()
{
    if(NULL == socket)
    {
        ui->textEditInfomation->append("Please connect\n");
        this->close();
    }
    else
    {
        socket->write("R",1);  //发送指令
        ui->textEditInfomation->append("右转\n");
    }
}

void RemoteWindow::on_pushButtonStop_pressed()
{
    if(NULL == socket)
    {
        ui->textEditInfomation->append("Please connect\n");
        this->close();
    }
    else
    {
        socket->write("B",1);  //发送指令
        ui->textEditInfomation->append("刹车\n");
    }
}



//创造按键一直按着小车才会一直走的效果
void RemoteWindow::on_pushButtonGoHead_released()
{
    socket->write("B",1);  //发送指令
    //ui->textEdit->append("停止\n");
}

void RemoteWindow::on_pushButtonTurnLeft_released()
{
    socket->write("B",1);  //发送指令
    //ui->textEdit->append("停止\n");
}

void RemoteWindow::on_pushButtonGoBack_released()
{
    socket->write("B",1);  //发送指令
    //ui->textEdit->append("停止\n");
}

void RemoteWindow::on_pushButtonTurnRight_released()
{
    socket->write("B",1);  //发送指令
    //ui->textEdit->append("停止\n");
}

void RemoteWindow::on_pushButtonStop_released()
{
    socket->write("B",1);  //发送指令
    //ui->textEdit->append("停止\n");
}




//==============================按键发送指令=================================


//===============================链接服务器===================================


void RemoteWindow::on_pushButtonLink_clicked()
{
    if(NULL == socket)
    {
        socket = new QTcpSocket();
        socket->connectToHost(ui->lineEditLinkIp->text(),ui->lineEditLinkPort->text().toUShort());
    }
    ui->textEditInfomation->append("服务器连接成功\n");

    socket->write("B",5);  //发送指令
}

//===============================链接服务器===================================










