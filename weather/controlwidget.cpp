#include "controlwidget.h"
#include "ui_controlwidget.h"
#include <QDebug>

devStatus miainDevIcon;
devStatus sysDevStatus;

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlWidget)
//    mMainWidget(qobject_cast<MainWidget*>(parent))
{
    ui->setupUi(this);
    ui->label_28->setStyleSheet("color:#4aa2a7; border:none;");
    setWindowFlag(Qt::FramelessWindowHint); // 设置窗口无边框
    setFixedSize(width(), height());

    /*****************************************************************/
    controlTimer = new QTimer;
    controlTimer->start(1000);
    connect(controlTimer, SIGNAL(timeout()), this, SLOT(timerTimeOut()));

//    voicSpecch = new specch();
//    recordVoiceThread = new record();
//    connect(recordVoiceThread,&record::recordCorlRunFlagSignal,recordVoiceThread,&record::recordCorlRunFlag);

    m_process = new QProcess;

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


/***************************************************************/
/*==============led===============*/
void ControlWidget::ledStatusSeting(devSwitchStatus switchStatus)
{
    QString buttonStyle;
    if(switchStatus==ON)
    {
        //     ledArguments << "/dev/led_dev"<<"on";
        buttonStyle= QString(" QPushButton {border-radius:28px;border-image: url(:/image/LEDSwitchON.png);background: rgba(0,0,0,0%);}");
    }
    else if(switchStatus==OFF)
    {
        //      ledArguments << "/dev/led_dev"<<"off";
        buttonStyle= QString(" QPushButton {border-radius:28px;border-image: url(:/image/LEDSwitchOFF.png);background: rgba(0,0,0,0%);}");
    }
    ui->pushButtonSetLED->setStyleSheet(buttonStyle);
    //    m_process->start("LED_control",ledArguments);
    //    m_process->waitForFinished();
    //    ledArguments.clear();
}

void ControlWidget::on_pushButtonSetLED_clicked()
{
    if(sysDevStatus.ledStatus==ON)
    {
        sysDevStatus.ledStatus=OFF;
    }
    else if( sysDevStatus.ledStatus==OFF)
    {
        sysDevStatus.ledStatus=ON;
    }
    ledStatusSeting(sysDevStatus.ledStatus);
}

/*==============door===============*/
void ControlWidget::doorStatusSeting(devSwitchStatus switchStatus)
{
    QString buttonStyle;
    if(switchStatus==ON)
    {
        buttonStyle= QString(" QPushButton {border-radius:28px;border-image: url(:/image/DoorSwitchON.png);background: rgba(0,0,0,0%);}");
    }
    else if(switchStatus==OFF)
    {
        buttonStyle= QString(" QPushButton {border-radius:28px;border-image: url(:/image/DoorSwitchOFF.png);background: rgba(0,0,0,0%);}");
    }
    ui->pushButtonSetDoor->setStyleSheet(buttonStyle);
}

void ControlWidget::on_pushButtonSetDoor_clicked()
{
    if(sysDevStatus.doorStatus==ON)
    {
        sysDevStatus.doorStatus=OFF;
    }
    else if( sysDevStatus.doorStatus==OFF)
    {
        sysDevStatus.doorStatus=ON;
    }
    doorStatusSeting(sysDevStatus.doorStatus);
}

void ControlWidget::condModeSeting(AcMode modeStatus)
{
    QString buttonStyle;
    QString labelStyle;

    if(modeStatus==ACHOT)
    {
        buttonStyle=QString(" QPushButton {border-radius: 5px;border-image: url(:/image/hot.png);}");
        labelStyle= QString("background-color: rgb(234, 243, 244);border-top-right-radius: 10px; border-bottom-right-radius: 10px;color:red;");
        ui->labMode->setText("HOT");
    }
    else if(modeStatus==ACCOLD)
    {
        buttonStyle= QString(" QPushButton {border-radius: 5px;border-image: url(:/image/cold.png);}");
        labelStyle= QString(" background-color: rgb(234, 243, 244);border-top-right-radius: 10px; border-bottom-right-radius: 10px;color:#1485fb;");
        ui->labMode->setText("COLD");
    }
    else
    {
        buttonStyle= QString(" QPushButton {border-radius: 5px;border-image: url(:/image/cold.png);}");
        labelStyle= QString(" background-color: rgb(234, 243, 244);border-top-right-radius: 10px; border-bottom-right-radius: 10px;color:#1485fb;");
        ui->labMode->setText("COLD");
    }
    ui->pushButtonSetMode->setStyleSheet(buttonStyle);
    ui->labSetTemperText->setStyleSheet(labelStyle);
}


void ControlWidget::on_pushButtonSetMode_clicked()
{
    if(sysDevStatus.condMode==ACHOT)
    {
        sysDevStatus.condMode=ACCOLD;
    }
    else if( sysDevStatus.condMode==ACCOLD)
    {
        sysDevStatus.condMode=ACHOT;
    }
    else
    {
        sysDevStatus.condMode=ACCOLD;
    }

    condModeSeting(sysDevStatus.condMode);

}
/*==============temperature===============*/
void ControlWidget::condSwStatusSeting(devSwitchStatus switchStatus)
{
    QString buttonStyle;
    if(switchStatus==ON)
    {
        buttonStyle= QString(" QPushButton {border-radius: 12px;border-image: url(:/image/TemperSwitchON.png);}");
        sysDevStatus.TermperSwitchStatus=ON;
    }
    else if(switchStatus==OFF)
    {
        buttonStyle= QString(" QPushButton {border-radius: 12px;border-image: url(:/image/TemperSwitchOFF.png);}");
        sysDevStatus.TermperSwitchStatus=OFF;
    }
    ui->pushButtonTemperSw->setStyleSheet(buttonStyle);
}


void ControlWidget::on_pushButtonTemperSw_clicked()
{

    if(sysDevStatus.condSWStatus==ON)
    {
        sysDevStatus.condSWStatus=OFF;
    }
    else if( sysDevStatus.condSWStatus==OFF)
    {
        sysDevStatus.condSWStatus=ON;
    }
    condSwStatusSeting(sysDevStatus.condSWStatus);

}
/*==============temperature adjust===============*/
void ControlWidget::on_pushButtonAdd_pressed()
{
    QString buttonStyle;
    buttonStyle= QString(" QPushButton {border-radius: 10px;background: rgba(0,0,0,0%);border-image: url(:/image/TempPressAdd.png);}");
    ui->pushButtonAdd->setStyleSheet(buttonStyle);

    if(sysDevStatus.TermperSwitchStatus==ON)
    {
        sysDevStatus.currentSetTermper+=0.5;
        ui->labSetTemperText->setText(QString::number(sysDevStatus.currentSetTermper)+"°C");
    }

}

void ControlWidget::on_pushButtonAdd_released()
{
    QString buttonStyle;
    buttonStyle= QString(" QPushButton {border-radius: 10px;background: rgba(0,0,0,0%);border-image: url(:/image/TempSwitchAdd.png);}");
    ui->pushButtonAdd->setStyleSheet(buttonStyle);
}


void ControlWidget::on_pushButtonSub_pressed()
{
    QString buttonStyle;
    buttonStyle= QString(" QPushButton {border-radius: 10px;background: rgba(0,0,0,0%);border-image: url(:/image/TempPressSub.png);}");
    ui->pushButtonSub->setStyleSheet(buttonStyle);

    if(sysDevStatus.TermperSwitchStatus==ON)
    {
        sysDevStatus.currentSetTermper-=0.5;
        ui->labSetTemperText->setText(QString::number(sysDevStatus.currentSetTermper)+"°C");
    }
}


void ControlWidget::on_pushButtonSub_released()
{
    QString buttonStyle;
    buttonStyle= QString(" QPushButton {border-radius: 10px;background: rgba(0,0,0,0%);border-image: url(:/image/TempSwitchSub.png);}");
    ui->pushButtonSub->setStyleSheet(buttonStyle);
}

/*==============hum===============*/
void ControlWidget::dehumSwStatusSeting(devSwitchStatus switchStatus)
{
    QString buttonStyle;
    if(switchStatus==OFF)
    {
        buttonStyle= QString(" QPushButton {border-radius: 12px;border-image: url(:/image/TemperSwitchOFF.png);}");
        sysDevStatus.HumSwitchStatus=OFF;
    }
    else if(switchStatus==ON)
    {
        buttonStyle= QString(" QPushButton {border-radius: 12px;border-image: url(:/image/TemperSwitchON.png);}");
        sysDevStatus.HumSwitchStatus=ON;
    }
    ui->pushButtonHumSw->setStyleSheet(buttonStyle);
}


void ControlWidget::on_pushButtonHumSw_clicked()
{
    if(sysDevStatus.dehumdifierStatus==ON)
    {
        sysDevStatus.dehumdifierStatus=OFF;
    }
    else if( sysDevStatus.dehumdifierStatus==OFF)
    {
        sysDevStatus.dehumdifierStatus=ON;
    }
    dehumSwStatusSeting(sysDevStatus.dehumdifierStatus);
}

/*==============hum adjust===============*/
void ControlWidget::on_pushButtonSetHumAdd_pressed()
{
    QString buttonStyle;
    buttonStyle= QString(" QPushButton {border-radius: 10px;background: rgba(0,0,0,0%);border-image: url(:/image/TempSwitchAdd.png);}");
    ui->pushButtonSetHumAdd->setStyleSheet(buttonStyle);

    if(sysDevStatus.HumSwitchStatus==ON)
    {
        sysDevStatus.currentSetHumidity+=0.5;
        ui->labSetHumidity->setText(QString::number(sysDevStatus.currentSetHumidity)+"%");
    }
}


void ControlWidget::on_pushButtonSetHumAdd_released()
{
    QString buttonStyle;
    buttonStyle= QString(" QPushButton {border-radius: 10px;background: rgba(0,0,0,0%);border-image: url(:/image/TempPressAdd.png);}");
    ui->pushButtonSetHumAdd->setStyleSheet(buttonStyle);
}


void ControlWidget::on_pushButtonSetHumSub_pressed()
{
    QString buttonStyle;
    buttonStyle= QString(" QPushButton {border-radius: 10px;background: rgba(0,0,0,0%);border-image: url(:/image/TempSwitchSub.png);}");
    ui->pushButtonSetHumSub->setStyleSheet(buttonStyle);

    if(sysDevStatus.HumSwitchStatus==ON)
    {
        sysDevStatus.currentSetHumidity-=0.5;
        ui->labSetHumidity->setText(QString::number(sysDevStatus.currentSetHumidity)+"%");
    }
}


void ControlWidget::on_pushButtonSetHumSub_released()
{
    QString buttonStyle;
    buttonStyle= QString(" QPushButton {border-radius: 10px;background: rgba(0,0,0,0%);border-image: url(:/image/TempPressSub.png);}");
    ui->pushButtonSetHumSub->setStyleSheet(buttonStyle);
}

void ControlWidget::timerTimeOut()
{
    ledStatusSeting(sysDevStatus.ledStatus);
    wifiSwStatusSeting(sysDevStatus.wifiStatus);
    bluetoothSwStatusSeting(sysDevStatus.bluetoothStatus);
    if(sysDevStatus.HumSwitchStatus==ON)
    {
        ui->labSetHumidity->setText(QString::number(sysDevStatus.currentSetHumidity)+"%");
    }
    dehumSwStatusSeting(sysDevStatus.dehumdifierStatus);
    if(sysDevStatus.TermperSwitchStatus==ON)
    {
        ui->labSetTemperText->setText(QString::number(sysDevStatus.currentSetTermper)+"°C");
    }
    condSwStatusSeting(sysDevStatus.condSWStatus);
    doorStatusSeting(sysDevStatus.doorStatus);
    condModeSeting(sysDevStatus.condMode);
}

/*==============wifi===============*/
void ControlWidget::wifiSwStatusSeting(devSwitchStatus switchStatus)
{
    QString buttonStyle;
    sysDevStatus.wifiStatus=switchStatus;
    if(switchStatus==OFF)
    {
        buttonStyle= QString(" QPushButton {border-radius: 12px;border-image: url(:/image/WIFISwitchOFF.png);background: rgba(0,0,0,0%);}");
    }
    else if(switchStatus==ON)
    {
        buttonStyle= QString(" QPushButton {border-radius: 12px;border-image: url(:/image/WIFISwitchON.png);background: rgba(0,0,0,0%);}");
    }
    ui->pushButtonSetWIFI->setStyleSheet(buttonStyle);
    //emit ctrl->sendDevSignal(switchStatus,devStatusFlag.bluetoothStatus);

}


void ControlWidget::on_pushButtonSetWIFI_clicked()
{
    if(sysDevStatus.wifiStatus==ON)
    {
        sysDevStatus.wifiStatus=OFF;
        ui->stackedWidgetSetting->setCurrentIndex(0);
    }
    else if( sysDevStatus.wifiStatus==OFF)
    {
        sysDevStatus.wifiStatus=ON;
        ui->stackedWidgetSetting->setCurrentIndex(1);
    }
    wifiSwStatusSeting(sysDevStatus.wifiStatus);

}

/*==============bluetooth===============*/
void ControlWidget::bluetoothSwStatusSeting(devSwitchStatus switchStatus)
{
    QString buttonStyle;
    sysDevStatus.bluetoothStatus=switchStatus;

    if(switchStatus==OFF)
    {
        buttonStyle= QString(" QPushButton {border-radius: 12px;border-image: url(:/image/BlueSwitchOFF.png);background: rgba(0,0,0,0%);}");
    }
    else if(switchStatus==ON)
    {
        buttonStyle= QString(" QPushButton {border-radius: 12px;border-image: url(:/image/BlueSwitchON.png);background: rgba(0,0,0,0%);}");
    }
    ui->pushButtonSetBlue->setStyleSheet(buttonStyle);
    //emit ctrl->sendDevSignal(devStatusFlag.wifiStatus,switchStatus);
}
void ControlWidget::on_pushButtonSetBlue_clicked()
{

    if(sysDevStatus.bluetoothStatus==ON)
    {
        sysDevStatus.bluetoothStatus=OFF;
    }
    else if( sysDevStatus.bluetoothStatus==OFF)
    {
        sysDevStatus.bluetoothStatus=ON;
    }
    bluetoothSwStatusSeting(sysDevStatus.bluetoothStatus);
}

/*==============voice===============*/
//void ControlWidget::on_pushButtonVoice_pressed()
//{
//    QString buttonStyle;
//    buttonStyle= QString(" QPushButton {border-radius: 21px;border-image: url(:/image/recordVoiceBackPress.png);background: rgba(0,0,0,0%);}");
//    ui->pushButtonVoice->setStyleSheet(buttonStyle);
//    ui->stackedWidgetSetting->setCurrentIndex(0);
//    qDebug()<<"Start record";
//    emit recordVoiceThread->recordCorlRunFlagSignal(1);
//    recordVoiceThread->start();

//}

//void ControlWidget::on_pushButtonVoice_released()
//{
//    QString buttonStyle;
//    buttonStyle= QString(" QPushButton {border-radius: 21px;border-image: url(:/image/recordVoiceBackRelace.png);background: rgba(0,0,0,0%);}");
//    ui->pushButtonVoice->setStyleSheet(buttonStyle);
//    emit recordVoiceThread->recordCorlRunFlagSignal(0);
//    qDebug()<<"Stop record";
//    QString resultText;
//    resultText=voicSpecch->speechIdentify(":/wav/receiv.wav");
//    qDebug()<<"reslut:"<<resultText;
//    voiceToText="你好";
//    voiceControl(voiceToText);

//    resultText=QString("   user:"+resultText+"\n");
//    ui->textEdit->append(resultText);
//    recordVoiceThread->exit();

//}


//void ControlWidget::voiceControl(QString Text)
//{
    //    if (Text=="开灯")
    //    {
    //        sysDevStatus.ledStatus=OFF;
    //        condSwStatusSeting(sysDevStatus.ledStatus);
    //    }
    //    else if (Text=="关灯")
    //    {
    //        sysDevStatus.ledStatus=ON;
    //        condSwStatusSeting(sysDevStatus.ledStatus);
    //    }
    //    else if (Text=="开空调")
    //    {
    //      sysDevStatus.condSWStatus=OFF;
    //      condSwStatusSeting(sysDevStatus.condSWStatus);
    //    }
    //    else if (Text=="关空调")
    //    {
    //      sysDevStatus.condSWStatus=ON;
    //      condSwStatusSeting(sysDevStatus.condSWStatus);
    //    }
    //    else if (Text=="开蓝牙")
    //    {
    //        sysDevStatus.bluetoothStatus=OFF;
    //        condSwStatusSeting(sysDevStatus.bluetoothStatus);
    //    }
    //    else if (Text=="关蓝牙")
    //    {
    //        sysDevStatus.bluetoothStatus=ON;
    //        condSwStatusSeting(sysDevStatus.bluetoothStatus);
    //    }
    //    else if (Text=="开无线网")
    //    {
    //        sysDevStatus.wifiStatus=OFF;
    //        condSwStatusSeting(sysDevStatus.wifiStatus);
    //    }
    //    else if (Text=="关无线网")
    //    {
    //        sysDevStatus.wifiStatus=ON;
    //        condSwStatusSeting(sysDevStatus.wifiStatus);
    //    }
//}


void ControlWidget::on_pushButtonEdit_clicked()
{
    ui->textEdit->clear();
}

