#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include "dbhelper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(100);

    mplayer_p = new QMediaPlayer(this); //设置mediaplayer对象
    mplayList_p = new QMediaPlaylist(this); //设置mediaplaylist对象
    mplayer_p->setPlaylist(mplayList_p); //给播放对象设置播放列表
    mplayList_p->setPlaybackMode(QMediaPlaylist::Loop); //设置播放模式为循环

    //连接歌曲进度变化的信号和槽
    connect(mplayer_p,&QMediaPlayer::positionChanged,this,&MainWindow::onMediaPlayerPositionChanged);

    //连接当前播放歌曲变化的信号和槽
    connect(mplayList_p,&QMediaPlaylist::currentMediaChanged,this,&MainWindow::onCurrentMediaChanged);
    //连接播放模式变化的信号和槽
    connect(mplayList_p,&QMediaPlaylist::playbackModeChanged,this,&MainWindow::onPlayBackModeChanged);

    songListInit();//加载歌单

    connect(timer,&QTimer::timeout,this,&MainWindow::onTimeOut);
    timer->start();


}

MainWindow::~MainWindow()
{
    delete ui;
    timer->stop();
}


void MainWindow::on_actionaddMusic_triggered() //点击添加音乐选项时
{
    //打开文件对话框->获取选择的文件路径
    QStringList files = QFileDialog::getOpenFileNames(this,"选择添加的歌曲文件","./","音频文件(*.mp3)");
    if(files.isEmpty())
    {
        return;
    }
    //循环添加歌曲到列表
    for(auto it : files)
    {
        QFileInfo info(it);
        QString lrc = it;
        lrc.replace(".mp3",".lrc");
        qDebug()<<lrc;
        if(dbhelper::getInstance()->addSong(it,info.baseName(),lrc)) //先放入数据库
        {
            mplayList_p->addMedia(QMediaContent(it));
            ui->songList_LW->addItem(info.baseName());
        }
    }
}

void MainWindow::on_songControl_PB_clicked() //歌曲播放控制按钮点击
{
    if(mplayer_p->state() == QMediaPlayer::PlayingState)
    {
        mplayer_p->pause(); //暂停
        ui->songControl_PB->setIcon(QIcon(":/icons/pause.png"));
    }
    else
    {
        mplayer_p->play(); //播放
        ui->songControl_PB->setIcon(QIcon(":/icons/play.png"));
    }
}

void MainWindow::on_next_PB_clicked()
{
    mplayList_p->next();
}

void MainWindow::on_prev_PB_clicked()
{
    mplayList_p->previous();
}

void MainWindow::onCurrentMediaChanged(const QMediaContent& content)
{
    if(content.isNull())
    {
        ui->songTitle_LB->clear();
        ui->songList_LW->setCurrentRow(-1);
        ui->songControl_PB->setIcon(QIcon(":/icons/pause.png"));
        return;
    }
    //获取当前歌曲的下标
    int index = mplayList_p->currentIndex();

    //标题显示对应的歌曲
    ui->songTitle_LB->setText(ui->songList_LW->item(index)->text());

    //设置列表中对应的歌曲为选中状态
    ui->songList_LW->setCurrentRow(index);


    //加载歌词
    QString filePath = content.canonicalUrl().toString();//获取文件路径

    filePath[0] = filePath[0].toUpper();
    //qDebug()<<filePath;
//    QString lrcPath = filePath.replace(".mp3",".lrc"); //替换后缀得到歌词路径
    QString lrcPath = dbhelper::getInstance()->getSonglryics(filePath); //通过数据库加载歌词
    m_lryics.clear(); //清理歌词缓存
    if(QFileInfo(lrcPath).isFile())//将歌词添加到listwidget上
    {
        readLrcFile(lrcPath);
        ui->lrycis_LW->clear();
        ui->lrycis_LW->addItems(m_lryics.values());
    }
    else
    {
        ui->lrycis_LW->addItem("未找到歌词文件");
    }
}

void MainWindow::on_LoopMode_PB_clicked()
{
    int backMode = mplayList_p->playbackMode();
    backMode = (backMode+1)%5;
    mplayList_p->setPlaybackMode(static_cast<QMediaPlaylist::PlaybackMode>(backMode));
}

void MainWindow::onPlayBackModeChanged(QMediaPlaylist::PlaybackMode stat)
{
    QStringList Text = {"currentItemOnce.png","currentItemLoop.png","sequential.png","loop.png","random.png"};
    ui->LoopMode_PB->setIcon(QIcon(":/icons/"+Text[stat]));
}

void MainWindow::onMediaPlayerPositionChanged(qint64 position)
{
    qint64 totalTime = mplayer_p->duration(); //歌曲总时长
    qint64 sliderMax = ui->horizontalSlider->maximum(); //滑条的最大值
    double value = (double)position / totalTime * sliderMax; //计算滑条的位置
    ui->horizontalSlider->setValue(value); //设置滑条

    //时间换算 ms->s
    totalTime /= 1000;
    position /=1000;
    //设置时间显示文本
    QString Text;
    Text += QString("%1:%2/").arg(position/60,2,10,QChar('0')).arg(position%60,2,10,QChar('0'));
    Text += QString("%1:%2").arg(totalTime/60,2,10,QChar('0')).arg(totalTime%60,2,10,QChar('0'));
    //显示时间
    ui->SongTime_LB->setText(Text);
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    //计算歌曲进度位置
    qint64 value = ui->horizontalSlider->value();
    qint64 max = ui->horizontalSlider->maximum();
    mplayer_p->setPosition((double)value/max*mplayer_p->duration());
    //重新同步进度条和歌曲
    connect(mplayer_p,&QMediaPlayer::positionChanged,this,&MainWindow::onMediaPlayerPositionChanged);
}

void MainWindow::on_horizontalSlider_sliderPressed()
{
    //解除进度条和歌曲的同步
    disconnect(mplayer_p,&QMediaPlayer::positionChanged,this,&MainWindow::onMediaPlayerPositionChanged);
}

void MainWindow::on_songList_LW_itemDoubleClicked(QListWidgetItem *item)
{
    int row = ui->songList_LW->row(item); //获取歌曲在歌单中的位置
    mplayList_p->setCurrentIndex(row);    //设置当前的歌曲
    mplayer_p->play();    //重新播放
    ui->songControl_PB->setIcon(QIcon(":/icons/play.png"));
}

void MainWindow::onTimeOut()
{
    if(m_lryics.isEmpty()) //没有歌词
    {
        return; //不操作
    }

    if(ui->lrycis_LW->currentRow() == -1) //没有设置选择中行
    {
        ui->lrycis_LW->setCurrentRow(0); //设置到第一行
        return;
    }

    qint64 position = mplayer_p->position();  //歌曲进度
    int row = ui->lrycis_LW->currentRow();    //当前显示行
    QList<qint64> timelist = m_lryics.keys(); //时间戳列表

    if(position < timelist[row]) //进度小于当前位置
    {
        //向前查找合适的位置
        while(row > 0)
        {
            row--; //跳过当前行
            if(position >= timelist[row])
            {
                break;
            }

        }
    }
    else if(position > timelist[row]) //进度大于当前位置
    {
        //向后查找合适的位置
        while(row < timelist.size() - 1)
        {
            if(position < timelist[row + 1]) //判断后一行
            {
                break;
            }
            row++;
        }
    }
    else
    {

    }

    QListWidgetItem* item =  ui->lrycis_LW->item(row); //获取设置行的对象
    ui->lrycis_LW->setCurrentItem(item); //设置显示对象
    ui->lrycis_LW->scrollToItem(item,QAbstractItemView::PositionAtCenter); //滚动到指定位置

}

void MainWindow::readLrcFile(QString lrcPath)
{
    QFile file(lrcPath);
    bool ret = file.open(QIODevice::ReadOnly|QIODevice::Text); //打开文件
    if(!ret) //打开失败
    {
        qDebug()<<"文件打开失败"<<file.errorString();
        return ;
    }
    //设置文件读取流
    QTextStream tStreamer(&file);

    while(!tStreamer.atEnd())
    {
        QString line = tStreamer.readLine();
        //qDebug()<<line;
        line.remove(0,1);
        //第一次分割  时间-歌词
        QStringList lineContent = line.split("]");
        //第二次分割 分-秒
        QStringList timeContent = lineContent[0].split(":");
        //合成毫秒级时间戳
        qint64 A1 = timeContent[0].toInt(); //分
        double A2 = timeContent[1].toDouble(); //秒
        qint64 position = (A1 * 60 + A2) * 1000; //换算为毫秒
        m_lryics.insert(position,lineContent[1]); //记录歌词
    }
}

void MainWindow::songListInit()
{
    QStringList list = dbhelper::getInstance()->getSonglist();
    for(auto it : list)
    {
        mplayList_p->addMedia(QMediaContent(it));
        ui->songList_LW->addItem(QFileInfo(it).baseName());
    }
}
