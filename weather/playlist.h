// // playlist.h
// #ifndef PLAYLIST_H
// #define PLAYLIST_H

// #include <QObject>
// #include <QList>
// #include <QUrl>

// class Playlist : public QObject
// {
//     Q_OBJECT

// public:
//     enum PlaybackMode {
//         Sequential,
//         CurrentItemInLoop
//         // 其他播放模式
//     };


// public:
//     explicit Playlist(QObject *parent = nullptr);

//     void addMedia(const QUrl &url);
//     bool removeMedia(int index);
//     void clear();
//     void setCurrentIndex(int index);
//     int currentIndex() const;
//     QUrl currentMedia() const;
//     int mediaCount() const;
//     void next();
//     void previous();
//     void setPlaybackMode(int mode);

// signals:
//     void currentIndexChanged(int index);

// private:
//     QList<QUrl> m_mediaList;
//     int m_currentIndex;
//     int m_playbackMode; // 0: 顺序播放, 1: 循环播放
// };

// #endif // PLAYLIST_H
