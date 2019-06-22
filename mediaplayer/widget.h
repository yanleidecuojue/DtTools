#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QListWidget>
#include <QLine>
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *btnAdd;
    QPushButton *btnClear;
    QPushButton *btnRemove;

    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QPushButton *btnSound;
    QPushButton *btnPrevious;
    QPushButton *btnNext;

    QHBoxLayout *HLay1;
    QHBoxLayout *HLay2;
    QHBoxLayout *HLay3;
    QVBoxLayout *VLay1;
    QVBoxLayout *VLay2;
    QGroupBox *GBox;
    QLabel *labCurMedia;
    QLabel *labRatio;
    QSlider *sliderPosition;

    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QListWidget *listWidget;
    QSlider *sliderVolumn;
    QString durationTime;
    QString positionTime;

    void on_listWidget_doubleClicked(const QModelIndex &index);
    void on_sliderVolumn_valueChanged(int value);
    void on_sliderPosition_valueChanged(int value);
    void iniUI();
};

#endif // DIALOG_H
