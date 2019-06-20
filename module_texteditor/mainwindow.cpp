#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800,800);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::openTextByIODevice(const QString &aFileName)
{
    //用IODevice方式打开文本文件
    QFile   aFile(aFileName);
    //文件不存在
    if(!aFile.exists())
        return false;
    if(!aFile.open(QIODevice::ReadOnly|QIODevice::Text))
        return false;
    ui->plainTextEdit->setPlainText(aFile.readAll());
    aFile.close();
    return true;

}

void MainWindow::on_openFileAction_triggered()
{
    QString curPath=QDir::currentPath();//获取系统当前目录
    QString dlgTitle="打开一个文件"; //对话框标题
    QString filter="程序文件(*.h *.cpp);;文本文件(*.txt);;所有文件(*.*)"; //文件过滤器
    QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    if (aFileName.isEmpty())
        return;
    openTextByIODevice(aFileName);
}
