#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <QMainWindow>
#include <QContextMenuEvent>
#include <QMenu>
#include <QWebEngineView>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class RemoteWindow; }
QT_END_NAMESPACE

class RemoteWindow : public QMainWindow
{
    Q_OBJECT

public:
    RemoteWindow(QWidget *parent = nullptr);
    ~RemoteWindow();

protected:
    void resizeEvent(QResizeEvent *);

protected:
    // 重写父类方法
    void contextMenuEvent(QContextMenuEvent *event);

private slots:

    void on_pushButtonGoHead_pressed();

    void on_pushButtonTurnLeft_pressed();

    void on_pushButtonGoBack_pressed();

    void on_pushButtonTurnRight_pressed();

    void on_pushButtonLink_clicked();

    void on_pushButtonGoHead_released();

    void on_pushButtonTurnLeft_released();

    void on_pushButtonGoBack_released();

    void on_pushButtonTurnRight_released();

private:
    Ui::RemoteWindow *ui;
    QWebEngineView* view;
    QTcpSocket *socket ;

private:
    QMenu *mExitMenu;   // 右键退出的菜单
    QAction *mExitAct;  // 退出行为 - 菜单项
    QAction *mReturnAct; // 返回行为 - 菜单项
};
#endif // REMOTECONTROL_H
