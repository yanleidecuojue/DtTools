#include "homepage.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
{
    initUI();
    setWindowTitle("首页");
    connect(btnMusicPlayer,SIGNAL(clicked()),this,SLOT(on_btnMusicPlayer_clicked()));
    connect(btnTextEditor,SIGNAL(clicked()),this,SLOT(on_btnTextEditor_clicked()));
    connect(musicPlayerWidget,SIGNAL(sendSignalOfMusicPlayer()),this,SLOT(reshow()));
    connect(textEditorWidget,SIGNAL(sendSignalOfTextEditor()),this,SLOT(reshow()));
}

//文本编辑器按钮的点击事件
void HomePage::on_btnTextEditor_clicked()
{
    //主界面关闭
    this->hide();
    //文本编辑器界面显示
    textEditorWidget->show();
}

//音乐播放器按钮点击事件
void HomePage::on_btnMusicPlayer_clicked()
{
    //主界面关闭
    this->hide();
    //音乐播放器界面显示
    musicPlayerWidget->show();
}

void HomePage::reshow()
{
    this->show();
}

void HomePage::initUI()
{
    //文本编辑器
    btnTextEditor = new QPushButton;
    QIcon textEditor_Icon;
    textEditor_Icon.addFile(tr(":/homepage/homepage_icons/texteditor.png"));
    btnTextEditor->setIcon(textEditor_Icon);
    //录屏
    btnScreenCap = new QPushButton;
    QIcon screenCap_Icon;
    screenCap_Icon.addFile(tr(":/homepage/homepage_icons/screencap.png"));
    btnScreenCap->setIcon(screenCap_Icon);

    //音乐播放器
    btnMusicPlayer = new QPushButton;
    QIcon musicPlayer_Icon;
    musicPlayer_Icon.addFile(tr(":/homepage/homepage_icons/musicplayer.png"));
    btnMusicPlayer->setIcon(musicPlayer_Icon);

    //视频播放器
    btnVideoPlayer = new QPushButton;
    QIcon videoPlayer_Icon;
    videoPlayer_Icon.addFile(tr(":/homepage/homepage_icons/videoplayer.png"));
    btnVideoPlayer->setIcon(videoPlayer_Icon);
    //布局
    QHBoxLayout *HLay1 = new QHBoxLayout;
    HLay1->addWidget(btnTextEditor);
    HLay1->addStretch();
    HLay1->addWidget(btnScreenCap);

    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(btnMusicPlayer);
    HLay2->addStretch();
    HLay2->addWidget(btnVideoPlayer);

    QVBoxLayout *VLay1 = new QVBoxLayout;
    VLay1->addLayout(HLay1);
    VLay1->addLayout(HLay2);
    setLayout(VLay1);

    setMinimumSize(800,800);
    setMaximumSize(1000,1000);





}

HomePage::~HomePage()
{

}
