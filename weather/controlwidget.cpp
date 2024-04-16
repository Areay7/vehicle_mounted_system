#include "controlwidget.h"
#include "ui_controlwidget.h"
#include <QDebug>

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlWidget)
//    mMainWidget(qobject_cast<MainWidget*>(parent))
{
    ui->setupUi(this);
    ui->label_28->setStyleSheet("color:#4aa2a7; border:none;");
    setWindowFlag(Qt::FramelessWindowHint); // 设置窗口无边框
    setFixedSize(width(), height());

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
        // 返回到 MainWidget
        qDebug() << "Return action triggered!";
            returnToMainWidget();

    });

}

ControlWidget::~ControlWidget()
{
    delete ui;
}

void ControlWidget::contextMenuEvent(QContextMenuEvent *event)
{
    // 弹出右键菜单
    mExitMenu->exec(QCursor::pos());
    event->accept();
}

void ControlWidget::returnToMainWidget()
{
    qDebug() << "Return to MainWidget!";
    // 例如，显示主界面并隐藏当前界面
        hide();
    MainWidget *mainWidget = new MainWidget();
    mainWidget->show();
}
