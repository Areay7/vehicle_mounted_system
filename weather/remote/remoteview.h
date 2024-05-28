#ifndef REMOTEVIEW_H
#define REMOTEVIEW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class RemoteViewWindow; }
QT_END_NAMESPACE

class RemoteViewWindow : public QMainWindow
{
    Q_OBJECT

public:
    RemoteViewWindow(QWidget *parent = nullptr);
    ~RemoteViewWindow();

protected:
    void resizeEvent(QResizeEvent *);

private slots:



private:
    Ui::RemoteViewWindow *ui;
    QWebEngineView* view;
    QTcpSocket *socket ;
};
#endif // REMOTEVIEW_H
