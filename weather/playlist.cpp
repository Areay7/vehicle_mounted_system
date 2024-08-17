// // playlist.cpp
// #include "playlist.h"

// Playlist::Playlist(QObject *parent)
//     : QObject(parent), m_currentIndex(-1), m_playbackMode(0) {}

// void Playlist::addMedia(const QUrl &url) {
//     m_mediaList.append(url);
//     if (m_mediaList.size() == 1) {
//         setCurrentIndex(0); // 自动将第一个项目设置为当前项
//     }
// }

// bool Playlist::removeMedia(int index) {
//     // 检查索引是否有效
//     if (index >= 0 && index < m_mediaList.size()) {
//         // 从列表中删除媒体
//         m_mediaList.removeAt(index);

//         // 如果当前索引是删除的项，并且列表不为空，则设置新当前项
//         if (m_currentIndex == index && !m_mediaList.isEmpty()) {
//             setCurrentIndex(qMin(m_currentIndex, m_mediaList.size() - 1));
//         }

//         // 成功删除媒体
//         return true;
//     }

//     // 索引无效，未能删除媒体
//     return false;
// }

// void Playlist::clear() {
//     m_mediaList.clear();
//     m_currentIndex = -1;
// }

// void Playlist::setCurrentIndex(int index) {
//     if (index >= 0 && index < m_mediaList.size()) {
//         m_currentIndex = index;
//         emit currentIndexChanged(m_currentIndex);
//     }
// }

// int Playlist::currentIndex() const {
//     return m_currentIndex;
// }

// QUrl Playlist::currentMedia() const {
//     if (m_currentIndex >= 0 && m_currentIndex < m_mediaList.size()) {
//         return m_mediaList[m_currentIndex];
//     }
//     return QUrl();
// }

// int Playlist::mediaCount() const {
//     return m_mediaList.size();
// }

// void Playlist::next() {
//     if (m_mediaList.isEmpty()) return;
//     int nextIndex = (m_currentIndex + 1) % m_mediaList.size();
//     setCurrentIndex(nextIndex);
// }

// void Playlist::previous() {
//     if (m_mediaList.isEmpty()) return;
//     int prevIndex = (m_currentIndex - 1 + m_mediaList.size()) % m_mediaList.size();
//     setCurrentIndex(prevIndex);
// }

// void Playlist::setPlaybackMode(int mode) {
//     m_playbackMode = mode;
// }
