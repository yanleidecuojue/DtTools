#include "widget.h"
#include"QPushButton"
#include"QHBoxLayout"
#include"QVBoxLayout"
#include "QGroupBox"
#include "QFileDialog"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    iniUI();
    setWindowTitle("Form created mannually");
}

Widget::~Widget()
{

}

void Widget::iniUI()
{
    btnAdd=new QPushButton(tr("添加"));
    QIcon btnAdd_Icon;
    btnAdd_Icon.addFile(tr(":/images/images/add.bmp"));
    btnAdd->setIcon(btnAdd_Icon);
    btnAdd->setLayoutDirection(Qt::LeftToRight);

    btnClear=new QPushButton(tr("清空"));
    QIcon btnClear_Icon;
    btnClear_Icon.addFile(tr(":/images/images/clear.bmp"));
    btnClear->setIcon(btnClear_Icon);
    btnClear->setLayoutDirection(Qt::LeftToRight);

    btnRemove=new QPushButton(tr("删除"));
    QIcon btnRemove_Icon;
    btnRemove_Icon.addFile(tr(":/images/images/remove.bmp"));
    btnRemove->setIcon(btnRemove_Icon);
    btnRemove->setLayoutDirection(Qt::LeftToRight);

    HLay1=new QHBoxLayout;
    HLay1->addWidget(btnAdd);
    HLay1->addWidget(btnClear);
    HLay1->addWidget(btnRemove);

    VLay1 = new QVBoxLayout;
    listWidget = new QListWidget;
    VLay1->addLayout(HLay1);
    VLay1->addWidget(listWidget);
    GBox = new QGroupBox;
    GBox->setTitle("播放列表");
    GBox->setLayout(VLay1);

    btnPlay=new QPushButton(tr("播放"));
    QIcon btnPlay_Icon;
    btnPlay_Icon.addFile(tr(":/images/images/play.bmp"));
    btnPlay->setIcon(btnPlay_Icon);
    btnPlay->setLayoutDirection(Qt::LeftToRight);

    btnPause=new QPushButton(tr("暂停"));
    QIcon btnPause_Icon;
    btnPause_Icon.addFile(tr(":/images/images/pause.bmp"));
    btnPause->setIcon(btnPause_Icon);
    btnPause->setLayoutDirection(Qt::LeftToRight);

    btnStop=new QPushButton(tr("停止"));
    QIcon btnStop_Icon;
    btnStop_Icon.addFile(tr(":/images/images/stop.bmp"));
    btnStop->setIcon(btnStop_Icon);
    btnStop->setLayoutDirection(Qt::LeftToRight);

    btnPrevious=new QPushButton(tr("上一个"));
    QIcon btnPrevious_Icon;
    btnPrevious_Icon.addFile(tr(":/images/images/previous.bmp"));
    btnPrevious->setIcon(btnPrevious_Icon);
    btnPrevious->setLayoutDirection(Qt::LeftToRight);

    btnNext=new QPushButton(tr("下一个"));
    QIcon btnNext_Icon;
    btnNext_Icon.addFile(tr(":/images/images/next.bmp"));
    btnNext->setIcon(btnNext_Icon);
    btnNext->setLayoutDirection(Qt::LeftToRight);

    btnSound=new QPushButton(tr("音量"));
    QIcon btnSound_Icon;
    btnSound_Icon.addFile(tr(":/images/images/sound.bmp"));
    btnSound->setIcon(btnSound_Icon);
    btnSound->setLayoutDirection(Qt::LeftToRight);

    sliderVolumn = new QSlider;
    sliderVolumn->setOrientation(Qt::Horizontal);
    sliderVolumn->setValue(100);

    HLay2=new QHBoxLayout;
    HLay2->addWidget(btnPlay);
    HLay2->addWidget(btnPause);
    HLay2->addWidget(btnStop);
    HLay2->addWidget(btnPrevious);
    HLay2->addWidget(btnNext);
    HLay2->addStretch();
    HLay2->addWidget(btnSound);
    HLay2->addWidget(sliderVolumn);

    labCurMedia = new QLabel;
    labCurMedia->setText("无视频");
    sliderPosition = new QSlider;
    sliderPosition->setOrientation(Qt::Horizontal);
    labRatio = new QLabel;
    labRatio->setText("进度");
    labRatio->setMinimumSize(80,0);

    HLay3 = new QHBoxLayout;
    HLay3->addWidget(labCurMedia);
    HLay3->addWidget(sliderPosition);
    HLay3->addWidget(labRatio);

    VLay2 = new QVBoxLayout;
    VLay2->addWidget(GBox);
    VLay2->addLayout(HLay2);
    VLay2->addLayout(HLay3);
    setLayout(VLay2);

}
