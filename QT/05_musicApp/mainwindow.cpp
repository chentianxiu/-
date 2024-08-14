#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_player = new QMediaPlayer(this);
    m_playlist = new QMediaPlaylist(this);
    m_alrm = new QTimer(this);
    m_player->setPlaylist(m_playlist);
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);

    connect(m_playlist,&QMediaPlaylist::playbackModeChanged,this,&MainWindow::on_PB_switchChanged);
    connect(m_playlist,&QMediaPlaylist::currentMediaChanged,this,&MainWindow::on_currentSongShow);

    connect(m_player,&QMediaPlayer::positionChanged,this,&MainWindow::on_MediaPositionChanged);
    connect(m_alrm,&QTimer::timeout,this,&MainWindow::on_currentSongLrcLineShow);
}

MainWindow::~MainWindow()
{
    delete ui;
    dbhelper::removeInstance();
    m_alrm->stop();
}


void MainWindow::on_actionadd_file_triggered()
{
    QStringList file = QFileDialog::getOpenFileNames(this,"选择添加的歌曲文件","./","音频文件(*.mp3)");
    if(file.empty()){
        return;
    }
    int flag = 0;
    for(auto it : file)
    {
        QString lrcpath = it;
        lrcpath.replace(".mp3",".lrc");
        QString name = QFileInfo(it).baseName();
        if(!dbhelper::getINstance()->findMusic(name)){
            if(dbhelper::getINstance()->addMusic(it,name,lrcpath)){
                flag++;
                m_playlist->addMedia(QMediaContent(it));
            }
        }
        QStringList list;
        if(ui->LW_song->count() == 0){
            ui->LW_song->addItem(name);
        }else{
            int flag1 = 0;
            for(int i = 0;i < ui->LW_song->count();i++)
            {
                QListWidgetItem *item = ui->LW_song->item(i);
                list.append(item->text());
            }
            for(auto it : list)
            {
                if(it == name){
                    flag1 = 1;
                }
            }
            if(flag1 == 0){
                ui->LW_song->addItem(name);
            }
        }
    }
    if(flag != 0){
        QMessageBox::information(this,"添加歌曲",QString("成功添加%1首歌曲!").arg(flag));
    }
}
void MainWindow::on_currentSongShow(QMediaContent content)
{
    if(!content.isNull()){
        int row = m_playlist->currentIndex();
        if (row < 0){
            return;
        }
        QString text = "正在播放:" + ui->LW_song->item(row)->text();
        ui->LA_name->setText(text);
        ui->LW_song->setCurrentRow(row);
        on_currentSongLrcShow(ui->LW_song->item(row)->text());
    }
}
void MainWindow::on_currentSongLrcShow(QString name)
{
    ui->LW_irc->clear();
    m_lrctime.clear();
    m_tandl.clear();
    QString lrcPath = dbhelper::getINstance()->getLrcPath(name);
    QFile file(lrcPath);
    if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            line.remove(0,1);
            QStringList m_lrc = line.split("]");
            QStringList m_time = m_lrc[0].split(":");
            qint64 m1 = m_time[0].toInt()*60000;
            qint64 m2 = m_time[1].toDouble()*1000;
            m_lrctime.push_back(m1+m2);
            m_tandl.insert(m1+m2,m_lrc[1]);
            ui->LW_irc->addItem(m_lrc[1]);
        }
        file.close();
        m_alrm->start(300);
    }
}
//void MainWindow::on_currentSongLrcLineShow()
//{
//    if(m_tandl.isEmpty()){
//        QString text = "暂无歌词,敬请期待!";
//        ui->LW_irc->addItem(text);
//        ui->LW_irc->setCurrentRow(0);
//        return;
//    }
//    if(ui->LW_irc->currentRow() < 0){
//        ui->LW_irc->setCurrentRow(0);
//        return;
//    }
//    qint64 current = m_player->position();
//    int row = ui->LW_irc->currentRow();
//    if(current < m_lrctime[row]){
//        if(current < m_lrctime[row-1]){
//            while (row > 0)
//            {
//                row--;
//                if(current >= m_lrctime[row]){
//                    break;
//                }
//            }
//        }else{
//            row--;
//        }
//    }else if(current > m_lrctime[row]){
//        if(current > m_lrctime[row+1]){
//            row++;
//            while (row > 0)
//            {
//                if(current <= m_lrctime[row+1]){
//                    break;
//                }
//                row++;
//            }
//        }
//    }
//    QListWidgetItem* item =  ui->LW_irc->item(row);
//    ui->LW_irc->setCurrentItem(item);
//    ui->LW_irc->scrollToItem(item,QAbstractItemView::PositionAtCenter); //滚动到指定位置
//}
void MainWindow::on_currentSongLrcLineShow()
{
    if(m_tandl.isEmpty()){
        ui->LW_irc->clear();
        QString text = "暂无歌词,敬请期待!";
        ui->LW_irc->addItem(text);
        ui->LW_irc->setCurrentRow(0);
        return;
    }
    double/*qint64*/ current = m_player->position();
    int row = 0;
    while(row < m_lrctime.size() - 1 && current >= m_lrctime[row + 1])
    {
        row++;
    }

    if(row < ui->LW_irc->count() && row != ui->LW_irc->currentRow()){
        ui->LW_irc->setCurrentRow(row);
        ui->LW_irc->scrollToItem(ui->LW_irc->item(row), QAbstractItemView::PositionAtCenter);
    }
}

void MainWindow::on_PB_status_clicked()
{
    if(m_player->state() == QMediaPlayer::PlayingState){
        m_player->pause();
        ui->PB_status->setIcon(QIcon(":/icons/pause.png"));
    }else if(m_playlist && m_playlist->mediaCount() > 0){
        m_player->play();
        ui->PB_status->setIcon(QIcon(":/icons/play.png"));
    }
}
void MainWindow::on_PB_previous_clicked()
{
    m_playlist->previous();
}
void MainWindow::on_PB_next_clicked()
{
    m_playlist->next();
}
void MainWindow::on_PB_switch_clicked()
{
    int songMode = m_playlist->playbackMode();
    songMode = (songMode+1)%5;
    m_playlist->setPlaybackMode(static_cast<QMediaPlaylist::PlaybackMode>(songMode));
}

void MainWindow::on_PB_switchChanged(QMediaPlaylist::PlaybackMode stat)
{
    QStringList text = {"currentItemOnce.png","currentItemLoop.png","sequential.png","loop.png","random.png"};
    ui->PB_switch->setIcon(QIcon(":/icons/"+text[stat]));
}



void MainWindow::on_HS_time_sliderPressed()
{
    disconnect(m_player,&QMediaPlayer::positionChanged,this,&MainWindow::on_MediaPositionChanged);
}
void MainWindow::on_HS_time_sliderReleased()
{
    double time = ui->HS_time->value();
    double max = ui->HS_time->maximum();
    double currentTime = /*(double)*/time/max*m_player->duration();
    m_player->setPosition(currentTime);
    connect(m_player,&QMediaPlayer::positionChanged,this,&MainWindow::on_MediaPositionChanged);
}

void MainWindow::on_MediaPositionChanged(qint64 position)
{
    qint64 allTime = m_player->duration();
    double sliderMax = ui->HS_time->maximum();
    double currentTime = /*(double)*/position/allTime*sliderMax;
    ui->HS_time->setValue(currentTime);

    position /= 1000;
    allTime /= 1000;
    QString text = QString("%1:%2/").arg(position/60,2,10,QChar('0')).arg(position%60,2,10,QChar('0')) +
                   QString("%1:%2").arg(allTime/60,2,10,QChar('0')).arg(allTime%60,2,10,QChar('0'));
    ui->LA_time->setText(text);
}


void MainWindow::on_LW_song_itemDoubleClicked(QListWidgetItem *item)
{
    if(!item){
        return;
    }
    int row = ui->LW_song->row(item);
    m_playlist->setCurrentIndex(row);
    m_player->play();
    ui->PB_status->setIcon(QIcon(":/icons/play.png"));
}
void MainWindow::on_LW_irc_itemDoubleClicked(QListWidgetItem *item)
{
    if(!item){
        return;
    }
    int row = ui->LW_irc->currentRow();
    if(row >= 0 && row < m_lrctime.size()){
        m_player->setPosition(m_lrctime[row]);
        if (m_player->state() != QMediaPlayer::PlayingState){
            m_player->play();
            ui->PB_status->setIcon(QIcon(":/icons/play.png"));
        }
        m_player->setPosition(m_lrctime[row]);
    }
}
