#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_btnOpenWeatherWindow_clicked();

    void on_btnOpenSituationWindow_clicked();

private:
    Ui::Form *ui;
    MainWindow *mainWindow;
};

#endif // MAINWIDGET_H
