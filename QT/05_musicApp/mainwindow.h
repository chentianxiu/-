#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QVector>
#include <QMap>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <QFileDialog>
#include <QFileInfo>
#include <QStringList>
#include <QListWidgetItem>
#include "dbhelper.h"

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
    void on_actionadd_file_triggered();
    void on_currentSongShow(QMediaContent content);
    void on_currentSongLrcShow(QString name);
    void on_currentSongLrcLineShow();


    void on_PB_status_clicked();
    void on_PB_previous_clicked();
    void on_PB_next_clicked();
    void on_PB_switch_clicked();
    void on_PB_switchChanged(QMediaPlaylist::PlaybackMode stat);


    void on_HS_time_sliderPressed();
    void on_HS_time_sliderReleased();
    void on_MediaPositionChanged(qint64 position);


    void on_LW_song_itemDoubleClicked(QListWidgetItem *item);
    void on_LW_irc_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_player;
    QMediaPlaylist *m_playlist;
    QVector<qint64> m_lrctime;
    QMap<qint64,QString> m_tandl;
    QTimer *m_alrm;
};
#endif // MAINWINDOW_H
