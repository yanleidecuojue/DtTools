//下面两句代码和最后一句代码是所有.h都拥有的，防止多重引用
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//将三个Qt写好的C++的类引用进来
//第一个是主应用窗口类
//第二个是与媒体资源播放有关的类
//第三个是提供播放器媒体内容列表的类
#include    <QMainWindow>
#include    <QMediaPlayer>
#include    <QMediaPlaylist>
//声明命名空间，将下方定义的类的内容放到Ui里面，ui_mainwindow.h文件中也有这个，是用来定义类的，与using namespace std类比记忆
namespace Ui {
class MainWindow;
}
//继承自QMainWindow的类
class MainWindow : public QMainWindow
{
    //很重要的一个宏，这个宏的展开将为我们的类提供信号槽机制、国际化机制以及Qt提供的不基于C++ RTTI的反射能力。
    Q_OBJECT

//私有数据成员
private:
    QMediaPlayer    *player;//播放器
    QMediaPlaylist  *playlist;//播放列表
    QString  durationTime;//总长度
    QString  positionTime;//当前播放到位置
public:
    //构造函数,QWidget *parent = 0,将0改为nullptr就不会报警告了
    explicit MainWindow(QWidget *parent = nullptr);
    //析构函数
    ~MainWindow();

private slots:
    //自定义槽函数
    //让播放，暂停，停止的某些按钮不可点击，可将鼠标移动到函数标识符上，并按住ctrl，点鼠标左键，进入具体实现
    void onStateChanged(QMediaPlayer::State state);
    //播放列表改变
    void onPlaylistChanged(int position);
    //播放进度改变
    void onDurationChanged(qint64 duration);
    //播放内容改变
    void onPositionChanged(qint64 position);

    void on_btnAdd_clicked();

    void on_btnPlay_clicked();

    void on_btnPause_clicked();

    void on_btnStop_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_btnClear_clicked();

    void on_sliderVolumn_valueChanged(int value);

    void on_btnSound_clicked();

//    void on_sliderPosition_valueChanged(int value);

//    void on_sliderPosition_sliderMoved(int position);

    void on_sliderPosition_valueChanged(int value);

    void on_btnRemove_clicked();

    void on_btnPrevious_clicked();

    void on_btnNext_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
