#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QPushButton>
#include <QSlider>
#include <QLabel>

//与媒体资源播放有关的类
#include <QMediaPlayer>
//提供播放器媒体内容列表的类
#include <QMediaPlaylist>
//提供媒体播放相关的框
#include <QVideoWidget>

#include "qvideoplayer.h"


class VideoPlayer : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayer(QWidget *parent = nullptr);
    ~VideoPlayer();

private:

    //返回首页按钮
    QPushButton *btnBack;
    //视频播放框
    QVideoPlayer *videoWidget;

    //视频播放器控制栏
    QPushButton *btnAdd;
    QPushButton *btnPlay;
    QPushButton *btnStop;
    QPushButton *btnPause;
    QPushButton *btnSound;
    QPushButton *btnFullScreen;
    QSlider *sliderVolumn;
    //视频播放器状态栏
    QLabel *labCurMedia;
    QSlider *sliderPosition;
    QLabel *labRatio;


    //UI创建与初始化
    void initUI();



private slots:
    void on_btnBack_clicked();

signals:
    void sendSignalOfVideoPlayer();

};

#endif // VIDEOPLAYER_H
