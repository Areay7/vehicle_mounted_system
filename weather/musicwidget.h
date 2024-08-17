// #ifndef MUSICWIDGET_H
// #define MUSICWIDGET_H

// #include <QWidget>
// // #include <QMediaPlaylist>
// #include <QMediaPlayer>
// // #include <QVideoWidget>
// #include <QListWidgetItem>
// #include "lyriclist.h"
// #include <QStackedWidget>

// #include <QtMultimedia>
// #include <QMediaPlayer>
// #include "playlist.h"

// class MainWidget;

// QT_BEGIN_NAMESPACE
// namespace Ui { class musicwidget; }
// QT_END_NAMESPACE

// class musicwidget : public QWidget
// {
//     Q_OBJECT

// public:
//     musicwidget(QWidget *parent = nullptr);
//     ~musicwidget();
//     void paintEvent(QPaintEvent *) override;
//     void musicPlayerInit(void);

// private slots:
//     void updatePosition(qint64 position);//�˦�
//     void updateDuration(qint64 duration);
//     void updateList(int value);

//     void on_startMusic_clicked();

// //    void on_musicList_itemClicked(QListWidgetItem *item);
//     void on_metaDataAvailableChanged(bool available);
//     void on_musicList_currentRowChanged(int currentRow);
//     void musicButtonStatus(bool buttonStatus);
//     void on_horizontalSlider_valueChanged(int value);

//     void on_nextMusic_clicked();

//     void on_proMusic_clicked();

//     void on_horizontalSlider_sliderReleased();

//     void on_fileLoad_clicked();

//     void on_musicVolume_2_sliderMoved(int position);

//     void on_musicVolume_clicked();

//     void on_musicOder_clicked();

//     void timerTimeOut();
//     void on_setBackground_clicked();

//     void on_musicList_customContextMenuRequested(const QPoint &pos);

// private:
//     Ui::musicwidget *ui;

//     QMediaPlayer  *music;
//     Playlist *playlist;
//     lyriclist * musicLyricList;

//     QPixmap disc;
//     QTimer* timer;
// };
// #endif // MUSICWIDGET_H
