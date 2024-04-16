#ifndef WIFILISTWIDGET_H
#define WIFILISTWIDGET_H

//#include <QWidget>
//#include <QCoreApplication>
//#include <QListWidget>
//#include <QInputDialog>
//#include <QProcess>
//#include <QMessageBox>
//#include <QGridLayout>
//#include <QPushButton>
//#include <QFormLayout>
//#include <QTimer>

//QT_BEGIN_NAMESPACE
//namespace Ui { class wifiListWidget; }
//QT_END_NAMESPACE

//enum keyBoardStatus
//{
//    KEYON,
//    KEYOFF
//};

//enum keycapStatus
//{
//    BIG,
//    LITTLE
//};


//class wifiListWidget : public QWidget
//{
//    Q_OBJECT

//public:
//    wifiListWidget(QWidget *parent = nullptr);
//    ~wifiListWidget();

//    void refreshWiFiList();
//    void connectWifi();
//    void setKeyboardStatus(keyBoardStatus s );
//    void setOtherStatus(keyBoardStatus s );
//    bool getWifiStatus();


//private slots:
//    void connectToWiFi();
//    void keyBoardEdit(void);
//    void keyBoardCancel(void);
//    void keyBoardAwaken(void);
//    void disconnectToWiFi(void);

//    void onButtonClicked(const QString &text);

//    void on_listWidgetWIFI_itemClicked(QListWidgetItem *item);
//    void readProcessOutput();
//    void timerTimeOut();
//private:
//    Ui::wifiListWidget *ui;
//    QListWidget *wifiList;
//    QLineEdit *passwordLineEdit;
//    keyBoardStatus keyBoardDev;
//    keycapStatus  keycapDev;
//    keyBoardStatus  OtherDev;
//    QPushButton *keycap[40];
//    QTimer * wifiTimer;
//    bool currentWifiExist;

//};

#endif // WIFILISTWIDGET_H
