#include "qvideoplayer.h"
#include    <QKeyEvent>
#include    <QMouseEvent>

void QVideoPlayer::keyPressEvent(QKeyEvent *event)
{//按键事件，ESC退出全屏状态
    if ((event->key() == Qt::Key_Escape)&&(isFullScreen()))
    {
        setFullScreen(false);
        event->accept();
        QVideoWidget::keyPressEvent(event);
    }
}

void QVideoPlayer::mousePressEvent(QMouseEvent *event)
{//鼠标事件，单击控制暂停和继续播放
    if (event->button()==Qt::LeftButton)
    {
        if (thePlayer->state()==QMediaPlayer::PlayingState)
          thePlayer->pause();
        else
          thePlayer->play();
    }
    QVideoWidget::mousePressEvent(event);

}

QVideoPlayer::QVideoPlayer(QWidget *parent):QVideoWidget(parent)
{

    setMinimumSize(1024,1024);
}

void QVideoPlayer::setMediaPlayer(QMediaPlayer *player)
{//设置播放器
    thePlayer=player;
}

