#include "musicplayer.h"
#include <QHBoxLayout>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFileDialog>

MusicPlayer::MusicPlayer(QWidget *parent)
    : QWidget(parent)
{
    //创建一个调色板对象
    QPalette musicplayer_palette = this->palette();
    musicplayer_palette.setBrush(QPalette::Background,QBrush(QPixmap(":/musicplayer/musicplayer_icons/musicplayer_background.jpg")));
    setPalette(musicplayer_palette);
    setWindowTitle("音乐播放器");
    initUI();//界面创建与布局
    initSignalSlot();//信号与槽的关联
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);//列表循环播放
    player->setPlaylist(playlist);

    connect(btnBack,SIGNAL(clicked()),this,SLOT(on_btnBack_clicked()));
    //播放状态变化的信号与槽实现
    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(onStateChanged(QMediaPlayer::State)));
    //当前文件播放位置变化，更新进度显示
    connect(player,SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));
    //文件时长变化，更新进度显示
    connect(player,SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));
    //播放列表变化,更新当前播放文件名显示
    connect(playlist,SIGNAL(currentIndexChanged(int)),
            this, SLOT(onPlaylistChanged(int)));
}

MusicPlayer::~MusicPlayer()
{

}
void MusicPlayer::on_btnBack_clicked()
{
    emit sendSignalOfMusicPlayer();
    this->close();
}
void MusicPlayer::initUI()
{

    //创建返回以及当前目录布局
    btnBack = new QPushButton;
    btnBack->setText(tr("返回"));
    QHBoxLayout *HLay1 = new QHBoxLayout;
    HLay1->addWidget(btnBack);
    HLay1->addStretch();


    //创建btnAdd,btnRemove,btnClear三个PushButton，并水平布局
    btnAdd = new QPushButton(tr("添加"));
    QIcon btnAdd_Icon;
    btnAdd_Icon.addFile(tr(":/musicplayer/musicplayer_icons/add.png"));
    btnAdd->setIcon(btnAdd_Icon);
    btnAdd->setLayoutDirection(Qt::LeftToRight);
    btnRemove = new QPushButton(tr("移除"));
    QIcon btnRemove_Icon;
    btnRemove_Icon.addFile(tr(":/musicplayer/musicplayer_icons/remove.png"));
    btnRemove->setIcon(btnRemove_Icon);
    btnRemove->setLayoutDirection(Qt::LeftToRight);
    btnClear = new QPushButton(tr("清空"));
    QIcon btnClear_Icon;
    btnClear_Icon.addFile(tr(":/musicplayer/musicplayer_icons/clear.png"));
    btnClear->setIcon(btnClear_Icon);
    btnClear->setLayoutDirection(Qt::LeftToRight);

    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(btnAdd);
    HLay2->addWidget(btnRemove);
    HLay2->addWidget(btnClear);

    //在VLay1中加入listWidget和HLay1之后竖直布局,并将其添加进GBox
    QVBoxLayout *VLay1 = new QVBoxLayout;
    listWidget = new QListWidget;
    VLay1->addLayout(HLay2);
    VLay1->addWidget(listWidget);
    QGroupBox *GBox = new QGroupBox;
    GBox->setTitle("播放列表");
    GBox->setLayout(VLay1);


    //创建播放，暂停，停止，上一曲，下一曲，声音控制，音量控制控件之后水平布局
    btnPlay = new QPushButton;
    QIcon btnPlay_Icon;
    btnPlay_Icon.addFile(tr(":/musicplayer/musicplayer_icons/broadcast.png"));
    btnPlay->setIcon(btnPlay_Icon);
    btnStop = new QPushButton;
    QIcon btnStop_Icon;
    btnStop_Icon.addFile(tr(":/musicplayer/musicplayer_icons/broadcastnow.png"));
    btnStop->setIcon(btnStop_Icon);
    btnPause = new QPushButton;
    QIcon btnPause_Icon;
    btnPause_Icon.addFile(tr(":/musicplayer/musicplayer_icons/pause.png"));
    btnPause->setIcon(btnPause_Icon);
    btnPrevious = new QPushButton;
    QIcon btnPrevious_Icon;
    btnPrevious_Icon.addFile(tr(":/musicplayer/musicplayer_icons/previous.png"));
    btnPrevious->setIcon(btnPrevious_Icon);
    btnNext = new QPushButton;
    QIcon btnNext_Icon;
    btnNext_Icon.addFile(tr(":/musicplayer/musicplayer_icons/next.png"));
    btnNext->setIcon(btnNext_Icon);
    btnSound = new QPushButton;
    QIcon btnSound_Icon;
    btnSound_Icon.addFile(tr(":/musicplayer/musicplayer_icons/volumn.png"));
    btnSound->setIcon(btnSound_Icon);
    sliderVolumn = new QSlider;
    sliderVolumn->setOrientation(Qt::Horizontal);
    sliderVolumn->setValue(100);


    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addWidget(btnPlay);
    HLay3->addWidget(btnStop);
    HLay3->addWidget(btnPause);
    HLay3->addWidget(btnPrevious);
    HLay3->addWidget(btnNext);
    HLay3->addStretch();
    HLay3->addWidget(btnSound);
    HLay3->addWidget(sliderVolumn);


    //创建当前媒体显示，播放内容控制，当前播放所在时间控件后添加到水平布局里面
    labCurMedia = new QLabel;
    labCurMedia->setText("无曲目");
    sliderPosition = new QSlider;
    sliderPosition->setOrientation(Qt::Horizontal);
    labRatio = new QLabel;
    labRatio->setText("进度");
    labRatio->setMinimumSize(80,0);

    QHBoxLayout *HLay4 = new QHBoxLayout;
    HLay4->addWidget(labCurMedia);
    HLay4->addWidget(sliderPosition);
    HLay4->addWidget(labRatio);


    //创建垂直布局，并设置为主布局
    QVBoxLayout *VLay2 = new QVBoxLayout;
    VLay2->addLayout(HLay1);
    VLay2->addWidget(GBox);
    VLay2->addLayout(HLay3);
    VLay2->addLayout(HLay4);
    setLayout(VLay2);


    //下面代码设置窗体为固定大小，如果想要让窗体在一定范围内变化，
    //使用setMinimumSize()和setMaximumSize()
    setMinimumSize(800,800);
    setMaximumSize(1000,1000);

}


void MusicPlayer::initSignalSlot()
{

    connect(btnAdd,SIGNAL(clicked()),this,SLOT(on_btnAdd_clicked()));
    connect(btnRemove,SIGNAL(clicked()),this,SLOT(on_btnRemove_clicked()));
    connect(btnClear,SIGNAL(clicked()),this,SLOT(on_btnClear_clicked()));

    connect(btnPlay,SIGNAL(clicked()),this,SLOT(on_btnPlay_clicked()));
    connect(btnPause,SIGNAL(clicked()),this,SLOT(on_btnPause_clicked()));
    connect(btnStop,SIGNAL(clicked()),this,SLOT(on_btnStop_clicked()));
    connect(btnPrevious,SIGNAL(clicked()),this,SLOT(on_btnPrevious_clicked()));
    connect(btnNext,SIGNAL(clicked()),this,SLOT(on_btnNext_clicked()));
    connect(btnSound,SIGNAL(clicked()),this,SLOT(on_btnSound_clicked()));
    connect(sliderVolumn,SIGNAL(valueChanged(int)),this,SLOT(on_sliderVolumn_valueChanged(int)));

    connect(sliderPosition,SIGNAL(valueChanged(int)),this,SLOT(on_sliderPosition_valueChanged(int)));

    connect(listWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_listWidget_doubleClicked(QModelIndex)));


}

void MusicPlayer::onStateChanged(QMediaPlayer::State state)
{
    //播放器状态变化，更新按钮状态
    btnPlay->setEnabled(!(state==QMediaPlayer::PlayingState));
    btnPause->setEnabled(state==QMediaPlayer::PlayingState);
    btnStop->setEnabled(state==QMediaPlayer::PlayingState);
}
void MusicPlayer::onPlaylistChanged(int position)
{
    //播放列表变化,更新当前播放文件名显示
    listWidget->setCurrentRow(position);
    QListWidgetItem  *item = listWidget->currentItem();
    if (item)
        labCurMedia->setText(item->text());
}

void MusicPlayer::onDurationChanged(qint64 duration)
{
     //文件时长变化，更新进度显示
     sliderPosition->setMaximum(duration);
     //计算机中的时间以milliseconds为单位
     int   secs=duration/1000;//秒
     int   mins=secs/60; //分钟
     secs=secs % 60;//余数秒
     durationTime=QString::asprintf("%d:%d",mins,secs);
     labRatio->setText(positionTime+"/"+durationTime);
}

void MusicPlayer::onPositionChanged(qint64 position)
{
    //当前文件播放位置变化，更新进度显示
    if (sliderPosition->isSliderDown())
        return;
    sliderPosition->setSliderPosition(position);
    int   secs=position/1000;//秒
    int   mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    positionTime=QString::asprintf("%d:%d",mins,secs);
    labRatio->setText(positionTime+"/"+durationTime);
}


//添加文件
void MusicPlayer::on_btnAdd_clicked()
{
    //获取系统当前目录
    QString curPath = QDir::homePath();
    //对话框标题
    QString dlgTitle = "选择音频文件";
    //文件过滤器
    QString filter = "音频文件(*.mp3 *.wav *.wma);;mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)";
    QStringList fileList = QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter);

    if(fileList.count()<1)
        return;

    for(int i=0;i<fileList.count();i++)
    {
        QString aFile = fileList.at(i);
        //添加文件
        playlist->addMedia(QUrl::fromLocalFile(aFile));
        //添加到界面文件列表
        QFileInfo fileInfo(aFile);
        listWidget->addItem(fileInfo.fileName());
    }

    if(player->state()!=QMediaPlayer::PlayingState)
        playlist->setCurrentIndex(0);
    player->play();
}

void MusicPlayer::on_btnRemove_clicked()
{
    //移除一个文件
    int pos = listWidget->currentRow();
    QListWidgetItem *item = listWidget->takeItem(pos);
    delete item;//从listWidget里删除

    if (playlist->currentIndex()==pos) //是当前播放的曲目
    {
        int nextPos = 0;
        if (pos >= 1)
            nextPos=pos-1;

        playlist->removeMedia(pos);//从播放列表里移除
        if (listWidget->count()>0)
        {
            playlist->setCurrentIndex(nextPos);
            onPlaylistChanged(nextPos);
        }
        else
        {
            player->stop();
            labCurMedia->setText("无曲目");
        }
    }
    else
        playlist->removeMedia(pos);
}

void MusicPlayer::on_btnClear_clicked()
{
    //清空列表
    playlist->clear();
    listWidget->clear();
    player->stop();
}

void MusicPlayer::on_btnPlay_clicked()
{
    //播放
    if (playlist->currentIndex()<0)
        playlist->setCurrentIndex(0);
    player->play();
}

void MusicPlayer::on_btnPause_clicked()
{
    //暂停播放
    player->pause();
}

void MusicPlayer::on_btnStop_clicked()
{
    //停止播放
    player->stop();
}

void MusicPlayer::on_btnPrevious_clicked()
{
    //前一文件
    playlist->previous();
}

void MusicPlayer::on_btnNext_clicked()
{
    //下一文件
    playlist->next();
}

void MusicPlayer::on_btnSound_clicked()
{
    //静音控制
    bool mute=player->isMuted();
    player->setMuted(!mute);
    if (mute)
        btnSound->setIcon(QIcon(":/musicplayer/musicplayer_icons/volumn.png"));
    else
        btnSound->setIcon(QIcon(":/musicplayer/musicplayer_icons/mute.png"));
}

void MusicPlayer::on_sliderVolumn_valueChanged(int value)
{
    //调整音量
    player->setVolume(value);
}

void MusicPlayer::on_listWidget_doubleClicked(const QModelIndex &index)
{
    //双击时切换播放文件
    int rowNo=index.row();
    playlist->setCurrentIndex(rowNo);
    player->play();
}

void MusicPlayer::on_sliderPosition_valueChanged(int value)
{
   //文件进度调控
   player->setPosition(value);
}
