#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QListWidget>
#include <QLine>
#include <QLabel>

//与媒体资源播放有关的类
#include <QMediaPlayer>
//提供播放器媒体内容列表的类
#include <QMediaPlaylist>


class Widget : public QWidget
{
    //很重要的一个宏，这个宏的展开将为我们的类提供信号槽机制、
    //国际化机制以及Qt提供的不基于C++ RTTI的反射能力。
    Q_OBJECT
private:
    QPushButton *btnAdd;
    QPushButton *btnClear;
    QPushButton *btnRemove;
    QListWidget *listWidget;

    QPushButton *btnPlay;
    QPushButton *btnStop;
    QPushButton *btnPause;
    QPushButton *btnPrevious;
    QPushButton *btnNext;
    QPushButton *btnSound;
    QSlider *sliderVolumn;

    QLabel *labCurMedia;
    QSlider *sliderPosition;
    QLabel *labRatio;

    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QString durationTime;
    QString positionTime;

    void initUI();//UI创建与初始化
    void initSignalSlot();//信号与槽的关联

private slots:
    //播放状态改变
    void onStateChanged(QMediaPlayer::State state);
    //播放列表改变
    void onPlaylistChanged(int position);
    //播放时间改变
    void onDurationChanged(qint64 duration);
    //播放进度改变
    void onPositionChanged(qint64 position);
    //添加文件
    void on_btnAdd_clicked();
    //移除文件
    void on_btnRemove_clicked();
    //清空播放列表
    void on_btnClear_clicked();
    //播放歌曲
    void on_btnPlay_clicked();
    //暂停播放的歌曲
    void on_btnPause_clicked();
    //停止播放的歌曲
    void on_btnStop_clicked();
    //前一文件
    void on_btnPrevious_clicked();
    //下一文件
    void on_btnNext_clicked();
    //静音控制
    void on_btnSound_clicked();
    //调整音量
    void on_sliderVolumn_valueChanged(int value);
    //播放文件进度调整
    void on_sliderPosition_valueChanged(int value);
    //双击时切换播放文件
    void on_listWidget_doubleClicked(const QModelIndex &index);
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

#endif // DIALOG_H
