#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "musicplayer.h"
#include "texteditor.h"
#include "videoplayer.h"
#include <QWidget>
#include <QPushButton>


class HomePage : public QWidget
{
    Q_OBJECT

public:
    HomePage(QWidget *parent = nullptr);
    ~HomePage();



    //文本编辑器
    QPushButton *btnTextEditor;
    //录屏
    QPushButton *btnScreenCap;
    //音乐播放器
    QPushButton *btnMusicPlayer;
    //视频播放器
    QPushButton *btnVideoPlayer;
    //UI创建与初始化
    void initUI();

private:

    //文本编辑器界面
    TextEditor *textEditorWidget = new TextEditor();

    //音乐播放器界面
    MusicPlayer *musicPlayerWidget = new MusicPlayer();

    //视频播放器界面
    VideoPlayer *videoPlayerWidget = new VideoPlayer();


private slots:

    //文本编辑器按钮的点击事件
    void on_btnTextEditor_clicked();
    //音乐播放器按钮的点击事件
    void on_btnMusicPlayer_clicked();
    //视频播放器按钮的点击事件
    void on_btnVideoPlayer_clicked();

    void reshow();
};

#endif // HOMEPAGE_H
