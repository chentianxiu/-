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
    void on_actionaddmusic_triggered();//点击添加音乐按钮

    void on_songControl_PB_clicked();//点击播放按钮

    void on_prev_PB_clicked();//上一首

    void on_next_PB_clicked();//下一首

    void on_LoopMode_PB_clicked();//歌曲播放模式切换

    void onPlayBackModeChanged(QMediaPlaylist::PlaybackMode stat);//模式切换时图片切换

    void on_horizontalSlider_sliderPressed();//进度条按钮按下

    void on_horizontalSlider_sliderReleased();//进度条按钮松开

    void on_songList_LW_doubleClicked(const QModelIndex &index);//双击列表中的这个项目时发生的事件

    void onCurrentMediaChanged(const QMediaContent &content);//切换歌曲时，各个的变化

    void onMediaPlayerPositionChanged(qint64 position);//滑条的设置和变化时的对应改变

    void onTimeOut();//歌词随着事件的变化
    void on_deleteSong_PB_clicked();//删除歌单按钮

    void on_lrycis_LW_doubleClicked(const QModelIndex &index);//双击歌词信息

    //void on_lrycis_LW_itemClicked(const QModelIndex &index);//鼠标单机事件
    void pauseTimerForThreeSeconds();//暂停3秒
    void resumeTimer();//重启计时器

private:
    Ui::MainWindow *ui;
    QMediaPlayer* mplayer_p; //播放对象
    QMediaPlaylist *mplayList_p;//播放列表
    QMap<qint64,QString> m_lryics; //歌词缓存,key是时间，值是歌词
    QTimer *timer; //播放计时器
    QTimer *pauseTimer;//暂停计时器
    bool isPaused;//记录自动计时器是否停止
    //bool isAutoUpdating;//设置一个标志位，判断是否自动更新

    void readLrcFile(QString lrcPath);//读取歌词
    void songListInit();//歌曲列表初始化
};
#endif // MAINWINDOW_H
