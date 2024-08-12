#ifndef MUSICROTATE_H
#define MUSICROTATE_H

#include <QWidget>

namespace Ui {
class musicrotate;
}

class musicrotate : public QWidget
{
    Q_OBJECT
    void paintEvent(QPaintEvent *) override;
public:
    explicit musicrotate(QWidget *parent = nullptr);
    ~musicrotate();
private slots:
    void timerTimeOut();

private:
    Ui::musicrotate *ui;
    QPixmap disc;
    QTimer* timer;
};

#endif // MUSICROTATE_H
