#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);
    ~TextEditor();


    //UI创建与初始化
    void initUI();

    //创建动作
    void createActions();

    //创建菜单栏
    void createMenuBar();

    //创建工具栏
    void createToolBar();
private:

    //控件的定义
    QPushButton *btnBack;
    QTextEdit *editText;
    //动作的定义
    QAction *openFileAction;
    QAction *newFileAction;
    QAction *exitAction;

private slots:

    void on_btnBack_clicked();
    //打开文件槽函数
    void on_openFile_triggered();
    //新建文件槽函数
    void on_newFile_triggered();

signals:
    void sendSignalOfTextEditor();


};

#endif // MAINWINDOW_H
