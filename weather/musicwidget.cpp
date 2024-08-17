// #include "musicwidget.h"
// #include "ui_musicwidget.h"
// #include <QListWidget>
// #include <QFileDialog>
// #include <QTimer>
// #include <QPixmap>
// #include <QPainter>
// #include <QDebug>
// #include <QMenu>
// #include <QDesktopServices>
// #include<stdio.h>

// QString currentFileName[1]={qApp->applicationDirPath()+ "/music/"};
// int buttonTollage=0;
// int musicLaunch=0;

// //converstion time s->ms
// static QString Time(qint64 time)
// {
//     qint64 seconds=time/1000;
//     const qint64 minutes=seconds/60;
//     seconds-=minutes*60;
//     return QStringLiteral("%1:%2")
//         .arg(minutes, 2, 10, QLatin1Char('0'))
//         .arg(seconds, 2, 10, QLatin1Char('0'));
// }

// QStringList getFileNamesInFolder(const QString& folderPath)
// {
//     QDir folderDir(folderPath);
//     QStringList fileNames = folderDir.entryList(QStringList() << "*.wav", QDir::Files);
//     return fileNames;
// }

// musicwidget::musicwidget(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::musicwidget)
// {
//     ui->setupUi(this);
//     musicPlayerInit();

//     //    connect(timer,SIGNAL(timeout()),this,SLOT(timerTimeOut()));

//     //当音乐播放器当前歌曲播放时间改变时
//     connect(music,&QMediaPlayer::positionChanged,this,&musicwidget::updatePosition);
//     //当音乐播放时间改变时触发的槽函数
//     connect(music,&QMediaPlayer::durationChanged,this,&musicwidget::updateDuration);
//     //当歌曲播放完成时触发的槽函数
//     // connect(playlist,&QMediaPlaylist::currentIndexChanged,this,&musicwidget::updateList);
//     //音乐播放器播切换歌曲时触发的槽函数
//     // connect(music,&QMediaPlayer::metaDataAvailableChanged,
//             // this,&musicwidget::on_metaDataAvailableChanged);

// }

// musicwidget::~musicwidget()
// {
// delete ui;
// }
// /*
//  *  initialize the individual components
//  *  rotation animation setting
//  *  initial component sytles setting: QSlider QPushButton QMediaPlayer/QMediaPlaylist QTabWidget QLabel
//  *  musicwidget background setting
//  *  playlist right-click the menu to trigger setting
//  */
// void musicwidget::musicPlayerInit()
// {
//     /*================rotation animation setting====================*/
//     //    timer = new QTimer();
//     //    timer->start(25);
//     musicLaunch=false;
//     /*================initial component sytles setting====================*/
//     /*-------QSlider---------*/
//     QString horizontalStyle3 = QString(
//         "QSlider::groove:horizontal{border: 1px solid  ;height:3px;}"
//         "QSlider::sub-page:horizontal{background: #f25d50;border-radius: 2px;}"
//         "QSlider::add-page:horizontal{background: #FFFFFF;border-radius: 2px;}"
//         "QSlider::handle:horizontal{border-image:url(:/image/Ellipse 2.png);width:15px;height:21px;margin-top:-6px;margin-bottom: -6px;}"
//         );

//     QString verticalStyle1 = QString(
//         "QSlider::groove:vertical {background: red;position: absolute; left: 13px; right: 13px;}"
//         "QSlider::handle:vertical {height: 13px;background: #11659a;margin: 0 -4px;border-radius: 6px;}"
//         "QSlider::sub-page:vertical {background: white;}"
//         "QSlider::add-page:vertical {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #813c85, stop:1 #ccccd6);}"
//         );
//     ui->horizontalSlider->setStyleSheet(horizontalStyle3);
//     ui->musicVolume_2->setStyleSheet(verticalStyle1);
//     ui->musicVolume_2->setValue(10);


//     /*-------QPushButton---------*/
//     QString buttonStyle=QString(" QPushButton {border-image: url(:/image/Group 3.1.png);}");
//     ui->startMusic->setStyleSheet(buttonStyle);

//     /*================initialize the individual components====================*/
//     /*-------QMediaPlayer---------*/
//     music = new QMediaPlayer(this);//create the music player
//     playlist = new Playlist(this);//create the music play list
//     playlist->setPlaybackMode(Playlist::Sequential);//Set playback mode
//     // music->setPlaylist(playlist);  //Set a playlist
//     playlist->addMedia(QUrl("file:///path/to/media1.mp3"));
//     playlist->addMedia(QUrl("file:///path/to/media2.mp3"));
//     ui->musicVolume_2->hide();//Hidden sound regulator
//     // music->setVolume(10);

//     /*-------QTabWidget---------*/
//     ui->tabWidget->setTabPosition(QTabWidget::East);
//     ui->tabWidget->setDocumentMode(true);
//     //    ui->tabWidget->setTabBarAutoHide(true);
//     ui->tabWidget->setTabShape(QTabWidget::Triangular);

//     /*-------musicwidget background setting---------*/
//     QString backgroundStyle=QString(" QFrame {border-image: url(:/image/back3.jpg);}");
//     // backgroundStyle.sprintf("QFrame#musicBackground{border-image: url(%s);}",":/image/back3.jpg");
//     ui->musicBackground->setStyleSheet(backgroundStyle);

//     //    QPalette pal =ui->musicBackground->palette();
//     //    //pal.setBrush(QPalette::Background,QBrush(QColor::fromRgb(11,11,11)));
//     //    pal.setBrush(QPalette::Window,QBrush(QPixmap(":/image/back3.jpg")));
//     //    setPalette(pal);
//     /*-------QLabel---------*/
//     ui->author->setStyleSheet("color: white");
//     ui->musicIfon->setStyleSheet("color: white");

//     //Set uneditable
//     ui->musicList->setEditTriggers(QAbstractItemView::NoEditTriggers);
//     ui->musicList->setSelectionMode(QAbstractItemView::SingleSelection);
//     ui->musicList->setSelectionBehavior(QAbstractItemView::SelectRows);
//     //playlist right-click menu
//     ui->musicList->setContextMenuPolicy(Qt::CustomContextMenu);


// }

// /*
//  * update QMediaPlayer
//  * Mouse click progress bar, progress bar one time forward/backward time
//  */
// void musicwidget::updatePosition(qint64 position)
// {
//     ui->horizontalSlider->setValue(position);//Set the slider position
//     ui->widget->lyricshow(position);
// }
// //Use the mouse to click the progress bar, the progress bar one time forward/backward time
// void musicwidget::updateDuration(qint64 duration)
// {
//     ui->horizontalSlider->setRange(0,duration);
//     ui->horizontalSlider->setEnabled(duration>0);
//     ui->horizontalSlider->setPageStep(duration/10);//????????????
// }
// /*
//  * When the current song index of the list changes,the list is updated,and
//  * the song autoamtically jumps to the next group after completion
//  */
// void musicwidget::updateList(int value)
// {
//     qDebug()<<"upvalue"<<value;
//     ui->musicList->item(value)->setSelected(true);
// }

// /*
//  * Music pause and start icon settings
//  */
// void musicwidget::on_startMusic_clicked()
// {
//     buttonTollage=!buttonTollage;
//     musicButtonStatus(buttonTollage);
// }
// /*
//  * buttonStatus=0 start
//  * buttonStatus=1 pause
//  */
// void musicwidget::musicButtonStatus(bool buttonStatus)
// {
//     QString buttonStyle;
//     if(buttonStatus)
//     {
//         music->play();
//         musicLaunch=true;
//         buttonStyle= QString(" QPushButton {border-image: url(:/image/Group 2.1.png);}");
//     }
//     else
//     {
//         music->pause();
//         musicLaunch=false;
//         buttonStyle=QString(" QPushButton {border-image: url(:/image/Group 3.1.png);}");
//     }
//     ui->startMusic->setStyleSheet(buttonStyle);
// }
// /*
//  * passive slot function,which is triggered when music changes
//  * loading music information
//  * loading lyrics
//  */
// void musicwidget::on_metaDataAvailableChanged(bool available)
// {
//     Q_UNUSED(available);
//     ui->widget->lyricsclaer();

//     // QString title=music->metaData("Title").toString();
//     // QString author=music->metaData("Author").toString();
//     // 获取 QMediaMetaData 对象
//     QMediaMetaData metaData = music->metaData();

//     // 从 QMediaMetaData 对象中获取 "Title" 元数据
//     QString title = metaData.value(QMediaMetaData::Title).toString();
//     QString author = metaData.value(QMediaMetaData::Author).toString();

//     if(title.isEmpty())
//     {
//         title="Mystery music";
//     }
//     if(author.isEmpty())
//     {
//         author="Mystery";
//     }

//     ui->musicIfon->setText(title);
//     ui->author->setText(author);

//     //loading lyric files
//     // 假设你已经在音乐播放器中加载了媒体
//     QString lrcPath = playlist->currentMedia().toLocalFile();
//     //QString picPath=lrcPath;
//     QString lrcName=lrcPath.remove(lrcPath.right(3))+"lrc";
//     // QString lrcBack=lrcPath.remove(picPath.right(3))+"jpg";

//     qDebug()<<"lrcPath"<<lrcPath;
//     qDebug()<<"lrcName"<<lrcName;
//     //   qDebug()<<"lrcBack"<<lrcBack;

//     //qDebug()<<"lyricHandle";
//      ui->widget->lyricsload(lrcName);
//     //   ui->widget->pictureload(lrcBack);
// }

// //the slot function is triggered when use mouse to click list
// void musicwidget::on_musicList_currentRowChanged(int currentRow)
// {
//         // qDebug()<<"currentRow"<<currentRow;
//         playlist->setCurrentIndex(currentRow);//setting current music
//         ui->musicList->scrollToItem(ui->musicList->item(currentRow));//roll current music
//         musicLaunch=true;
//         buttonTollage=true;
//         musicButtonStatus(buttonTollage);//start playing
// }

// //Update the current song time using the slot function triggered by dragging the progress bar with the mouse
// void musicwidget::on_horizontalSlider_valueChanged(int value)
// {
//         //qDebug()<<"value"<<value;
//         QString time=Time(value);
//         ui->label->setText(time);
// }

// /*
//  * Use the buttons to adjust the song to the next one
//  * Update play list
//  */
// void musicwidget::on_nextMusic_clicked()
// {
//     int row = playlist->mediaCount();//
//     // qDebug()<<"row"<<row;
//     int current  = playlist->currentIndex();//
//     //  qDebug()<<"next current"<<current;
//     if(++current>=row){
//         current=0;
//     }
//     playlist->setCurrentIndex(current);//
//     ui->musicList->scrollToItem(ui->musicList->item(current));//
//     buttonTollage=true;
//     musicLaunch=true;
//     musicButtonStatus(buttonTollage);//
// }

// /*
//  * Use the buttons to adjust the music to previous
//  * Update play list
//  */
// void musicwidget::on_proMusic_clicked()
// {
//     int row = playlist->mediaCount();//get number of music
//     int current  = playlist->currentIndex();//get current list Index
//     // qDebug()<<"pro current"<<current;
//     if(--current<0){
//          current=row-1;
//     }
//     playlist->setCurrentIndex(current);//setting current music
//     ui->musicList->scrollToItem(ui->musicList->item(current));//Scroll to current music
//     buttonTollage=true;
//     musicLaunch=true;
//     musicButtonStatus(buttonTollage);//Start playing
// }

// //Use the mouse to drag the slot function triggered when the progress bar is released??update music playing time
// void musicwidget::on_horizontalSlider_sliderReleased()
// {
//     // qDebug()<<"sliderReleased:"<<ui->horizontalSlider->value();

//     music->setPosition(ui->horizontalSlider->value());
// }

// /*
//  *  Import songs through folders
//  *  Import a music to ui->musicList  playlist->addMedia
//  */
// void musicwidget::on_fileLoad_clicked()
// {

//     QStringList fileNames=QFileDialog::getOpenFileNames(this,"select","D:/my_resource/projects/QT/MusicPlayer/Music/QMusic/Qmusic","music(*.mp3 *.wav)");
//     int fileCount=fileNames.count();
//     if(fileCount==0) return;

//     for(int i=0;i<fileCount;i++){
//         //将音频文件路径添加到音乐播放列表
//          playlist->addMedia(QUrl::fromLocalFile(fileNames.at(i)));
//          qDebug()<<"QUrl"<<QUrl::fromLocalFile(fileNames.at(i));

//          QString path=fileNames.at(i);
//          qDebug()<<"path"<<path;

//          //取出歌曲名称，添加到QListWidget
//          QListWidgetItem *item = new QListWidgetItem(path.mid(path.lastIndexOf('/')+1));
//          item->setToolTip(path);
//          ui->musicList->addItem(item);
//     }

//     // music->setPlaylist(playlist);

//      //加载最后一个文件//
//     playlist->setCurrentIndex(playlist->mediaCount()-1);
//     qDebug()<<"mediaCount"<<playlist->mediaCount()-1;

//     buttonTollage=false;
//     musicButtonStatus(buttonTollage);//暂停播放
// }


// //volume setting
// void musicwidget::on_musicVolume_2_sliderMoved(int position)
// {
//     QString volumeStyle;
//     // qDebug()<<"volume"<< music->volume();
//     // if(music->volume()<=3)
//     // {
//     //  volumeStyle=QString(" QPushButton {border-image: url(:/image/quietVolume.png);}");
//     // }
//     // else
//     // {
//     // volumeStyle=QString(" QPushButton {border-image: url(:/image/Volume.png);}");
//     // }
//     // ui->musicVolume->setStyleSheet(volumeStyle);
//     // music->setVolume(position);
// }

// //volume progress bar hide and display
// void musicwidget::on_musicVolume_clicked()
// {
//     static int volumeStatus=0;
//     volumeStatus=!volumeStatus;
//     if(volumeStatus)
//     {
//         ui->musicVolume_2->show();
//     }
//     else
//     {
//         ui->musicVolume_2->hide();
//     }
// }

// //playing mode
// void musicwidget::on_musicOder_clicked()
// {
//     static int oderStatus=1;
//     QString oderStyle;

//     oderStatus=!oderStatus;
//     if(oderStatus)
//     {
//        oderStyle=QString(" QPushButton {border-image: url(:/image/Vector.png);}");
//        playlist->setPlaybackMode(Playlist::Sequential);//Set play mode (sequential play)
//     }
//     else
//     {
//        oderStyle=QString(" QPushButton {border-image: url(:/image/Group.png);}");
//        playlist->setPlaybackMode(Playlist::CurrentItemInLoop);//Set playback mode (Single loop)
//     }
//     ui->musicOder->setStyleSheet(oderStyle);
// }

// void musicwidget::paintEvent(QPaintEvent *)
// {

// }

// void musicwidget::timerTimeOut()
// {

// }
// //setting background
// void musicwidget::on_setBackground_clicked()
// {
//     QString fileNames=QFileDialog::getOpenFileName(this,"select",".","music(*.png *.jpg *.jpeg)");

//     int fileCount=fileNames.count();
//     qDebug()<<"fileCount"<<fileCount;
//     if(fileCount==0) return;

//     qDebug()<<"fileNames"<<fileNames;
//     //    QPalette pal =this->palette();
//     //    //pal.setBrush(QPalette::Background,QBrush(QColor::fromRgb(11,11,11)));
//     //    pal.setBrush(QPalette::Window,QBrush(QPixmap(fileNames)));
//     //    setPalette(pal);
//     QString backgroundStyle=QString(" QFrame {border-image: url(:/image/back3.jpg);}");
//     // backgroundStyle.sprintf("QFrame#musicBackground{border-image: url(%s);}",qPrintable(fileNames));
//     ui->musicBackground->setStyleSheet(backgroundStyle);
// }

// //playlist right-click menu
// void musicwidget::on_musicList_customContextMenuRequested(const QPoint &pos)
// {
//     Q_UNUSED(pos);
//     QMenu musicListMenu;
//     QAction *actOpen=musicListMenu.addAction("open path");
//     QAction *actRemoveList=musicListMenu.addAction("remove from playlist");
//     QAction *actRemoveFile=musicListMenu.addAction("remove from disk");
//     QAction *actClear=musicListMenu.addAction("clear playlist");
//     QAction *actRes=musicListMenu.exec(QCursor::pos());
//     qDebug()<<"musicListMenu";
//     if(actRes)
//     {
//        int currentRow=ui->musicList->currentRow();
//        auto selectFirst=ui->musicList->currentItem();
//        QString path=selectFirst->toolTip();//Select the path to music

//        if(selectFirst==nullptr) return;
//        if(actRes==actOpen)
//        {
//            //fromLocalFile can solve path Chinese
//            QDesktopServices::openUrl(QUrl::fromLocalFile(
//                path.left(path.lastIndexOf('/'))));

//        }else if(actRes==actRemoveList)
//        {
//            if(playlist->removeMedia(currentRow))
//            {//delete success
//                auto removeItem=ui->musicList->takeItem(currentRow);
//                delete removeItem;
//            }
//        }else if(actRes==actRemoveFile)
//        {
//            QFile fe(path);
//            if(fe.remove())
//            {//delete success
//                playlist->removeMedia(currentRow);
//                auto removeItem=ui->musicList->takeItem(currentRow);
//                delete removeItem;
//            }
//        }else if(actRes==actClear)
//        {
//            playlist->clear();
//            ui->musicList->clear();
//            ui->label->setText("00:00");
//            ui->musicIfon->setText("name");
//            ui->author->setText("author");
//            buttonTollage=false;
//            musicLaunch=false;
//            musicButtonStatus(buttonTollage);
//        }
//     }

// }

