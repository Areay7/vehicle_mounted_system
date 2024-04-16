#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QContextMenuEvent>
#include <QMenu>
#include "mainwidget.h"

namespace Ui {
class ControlWidget;
}

class ControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlWidget(QWidget *parent = nullptr);
    ~ControlWidget();

protected:
    // 重写父类方法
    void contextMenuEvent(QContextMenuEvent *event);
private:
//    MainWidget *mMainWidget;

private:
    Ui::ControlWidget *ui;

    QMenu *mExitMenu;   // 右键退出的菜单
    QAction *mExitAct;  // 退出行为 - 菜单项
    QAction *mReturnAct; // 返回行为 - 菜单项

public slots:
    void returnToMainWidget();

};

#endif // CONTROLWIDGET_H
