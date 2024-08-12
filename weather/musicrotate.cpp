#include "musicrotate.h"
#include "ui_musicrotate.h"
#include <QTimer>
#include <QPixmap>
#include <QPainter>
extern int musicLaunch;

musicrotate::musicrotate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::musicrotate)
{
    ui->setupUi(this);
    disc = QPixmap(":/image/CDx.png");
    timer = new QTimer();
    timer->start(25);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTimeOut()));
}

musicrotate::~musicrotate()
{
    delete ui;
}
/*
 * Rotating picture
 * setting the center point of rotation
 * drawing opreation
 */
void musicrotate::paintEvent(QPaintEvent *)
{
    static int angle=0;
    if(musicLaunch)
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing
                               | QPainter::SmoothPixmapTransform);
        /* 碟机转动 */
        if(angle++ == 360)
            angle = 0;
        //设定旋转中心点
        /* QRectF 即，继承 QRect（Qt 的矩形类）， F 代表精确到浮点类型 */
        QRect rect((this->width()+30 - disc.width())/2,
                   (this->height() - disc.height())/2,
                   disc.width(),
                   disc.height());
        /* 默认参考点为左上角原点（0,0），因为旋转需要以图形的中心为参考点，
            * 我们使用 translate 把参考点设置为 CD 图形的中心点坐标 */
        painter.translate(0 + rect.x() + rect.width() / 2,
                          0 + rect.y() + rect.height() / 2);
        /* 旋转的角度 */
        painter.rotate(angle);
        //恢复中心点；
        /* 现在参考点为 CD 图形的中心，我们需要把它设置回原点的位置，
            * 所以需要减去上面加上的数 即将绘图的起点设置回起点*/
        painter.translate(0 - (rect.x() + rect.width() / 2),
                          0 - (rect.y() + rect.height() / 2));
        //画图操作
        /* 画图,QPainter 提供了许多 drawX 的方法 */
        painter.drawPixmap(rect,disc);
    }
}

void musicrotate::timerTimeOut()
{
    if(musicLaunch)
    {
        update();
    }
}
