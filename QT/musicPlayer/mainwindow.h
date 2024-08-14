#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaContent>
#include <QListWidgetItem>
#include <QMap>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionaddMusic_triggered();

    void on_songControl_PB_clicked();

    void on_next_PB_clicked();

    void on_prev_PB_clicked();

    void onCurrentMediaChanged(const QMediaContent &content);

    void on_LoopMode_PB_clicked();

    void onPlayBackModeChanged(QMediaPlaylist::PlaybackMode stat);

    void onMediaPlayerPositionChanged(qint64 position);

    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_sliderPressed();

    void on_songList_LW_itemDoubleClicked(QListWidgetItem *item);

    void onTimeOut();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* mplayer_p; //播放对象
    QMediaPlaylist *mplayList_p;//播放列表
    QMap<qint64,QString> m_lryics; //歌词缓存
    QTimer *timer; //播放计时器

    void readLrcFile(QString lrcPath);
    void songListInit();
};
#endif // MAINWINDOW_H
