#include "videoplayer.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

VideoPlayer::VideoPlayer(QWidget *parent) : QWidget(parent)
{
    initUI();

    connect(btnBack,SIGNAL(clicked()),this,SLOT(on_btnBack_clicked()));

}
VideoPlayer::~VideoPlayer()
{
}

void VideoPlayer::on_btnBack_clicked()
{

    emit sendSignalOfVideoPlayer();
    this->close();
}

void VideoPlayer::initUI()
{
    //创建返回以及当前目录布局
    btnBack = new QPushButton;
    btnBack->setText(tr("返回"));
    QHBoxLayout *HLay1 = new QHBoxLayout;
    HLay1->addWidget(btnBack);

    //创建播放框
    videoWidget = new QVideoPlayer();
    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(videoWidget);
    QGroupBox *GBox = new QGroupBox;
    GBox->setTitle("nihao");
    GBox->setLayout(HLay2);

    //控制栏控件的初始化
    btnAdd = new QPushButton;
    QIcon btnAdd_Icon;
    btnAdd_Icon.addFile(tr(":/videoplayer/videoplayer_icons/openfile.png"));
    btnAdd->setIcon(btnAdd_Icon);
    btnPlay = new QPushButton;
    QIcon btnPlay_Icon;
    btnPlay_Icon.addFile(tr(":/videoplayer/videoplayer_icons/broadcast.png"));
    btnPlay->setIcon(btnPlay_Icon);
    btnStop = new QPushButton;
    QIcon btnStop_Icon;
    btnStop_Icon.addFile(tr(":/videoplayer/videoplayer_icons/broadcast_now.png"));
    btnStop->setIcon(btnStop_Icon);
    btnPause = new QPushButton;
    QIcon btnPause_Icon;
    btnPause_Icon.addFile(tr(":/videoplayer/videoplayer_icons/pause.png"));
    btnPause->setIcon(btnPause_Icon);
    btnSound = new QPushButton;
    QIcon btnSound_Icon;
    btnSound_Icon.addFile(tr(":/videoplayer/videoplayer_icons/volumn.png"));
    btnSound->setIcon(btnSound_Icon);
    btnFullScreen = new QPushButton;
    QIcon btnFullScreen_Icon;
    btnFullScreen_Icon.addFile(tr(":/videoplayer/videoplayer_icons/fullscreen.png"));
    btnFullScreen->setIcon(btnFullScreen_Icon);
    sliderVolumn = new QSlider;
    sliderVolumn->setOrientation(Qt::Horizontal);
    sliderVolumn->setValue(100);
    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addWidget(btnAdd);
    HLay3->addWidget(btnPlay);
    HLay3->addWidget(btnStop);
    HLay3->addWidget(btnPause);
    HLay3->addStretch();
    HLay3->addWidget(btnSound);
    HLay3->addWidget(sliderVolumn);
    HLay3->addWidget(btnFullScreen);


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

    QVBoxLayout *VLay1 = new QVBoxLayout;
    VLay1->addLayout(HLay3);
    VLay1->addLayout(HLay4);






    //设置主布局，并加入控件
    QVBoxLayout *VLay2 = new QVBoxLayout;
    VLay2->addLayout(HLay1);
    VLay2->addWidget(GBox);
    VLay2->addLayout(VLay1);
    setLayout(VLay2);





    //下面代码设置窗体为固定大小，如果想要让窗体在一定范围内变化，
    //使用setMinimumSize()和setMaximumSize()




}
