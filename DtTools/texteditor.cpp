#include "texteditor.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>
#include <QTextStream>

TextEditor::TextEditor(QWidget *parent)
    : QMainWindow(parent)
{
    initUI();
    createActions();
    createMenuBar();
    createToolBar();
    connect(btnBack,SIGNAL(clicked()),this,SLOT(on_btnBack_clicked()));
    connect(openFileAction,SIGNAL(triggered()),this,SLOT(on_openFile_triggered()));
}

TextEditor::~TextEditor()
{

}

void::TextEditor::on_btnBack_clicked()
{
    emit sendSignalOfTextEditor();
    this->close();
}

void TextEditor::initUI()
{

   //返回按钮布局
   btnBack = new QPushButton(tr("返回"));
   QHBoxLayout *HLay1 = new QHBoxLayout;
   HLay1->addWidget(btnBack);

   //文本编辑框
   editText = new QTextEdit();
   QHBoxLayout *HLay2 = new QHBoxLayout;
   HLay2->addWidget(editText);

   //主布局的设置
   QWidget *widget = new QWidget();
   this->setCentralWidget(widget);
   QVBoxLayout *VLay1 = new QVBoxLayout;
   VLay1->addLayout(HLay1);
   VLay1->addLayout(HLay2);


//   VLay1->addLayout(HLay2);

   centralWidget()->setLayout(VLay1);

   setFixedSize(800,800);
}

void TextEditor::createActions()
{
   //打开动作
   openFileAction = new QAction(tr("打开") , this);
   openFileAction->setShortcut(tr("Ctrl + O"));
   openFileAction->setStatusTip(tr("打开一个文件"));
   connect(openFileAction,SIGNAL(triggered(bool)),this,SLOT(showOpenFile()));

   //新建动作
   newFileAction = new QAction(tr("新建") ,this );
   newFileAction->setShortcut(tr("Ctrl + N"));
   newFileAction->setStatusTip(tr("新建一个文件"));
   connect(newFileAction,SIGNAL(triggered()),this,SLOT(showNewFile()));

   //退出动作
   exitAction = new QAction(tr("退出"), this);
   exitAction->setShortcut(tr("Ctrl + Q"));
   exitAction->setStatusTip(tr("退出程序"));
   connect(exitAction,SIGNAL(triggered(bool)),this,SLOT(close()));



}

void TextEditor::createMenuBar()
{
   QMenuBar *menuBar = new QMenuBar(this);
   QMenu *menu = new QMenu("文件",this);
   menu->addAction(openFileAction);
   menu->addAction(newFileAction);
   menu->addAction(exitAction);

   menuBar->addMenu(menu);
   this->setMenuBar(menuBar);
}

void TextEditor::createToolBar()
{
    QToolBar *toolBar = new QToolBar(this);
    toolBar->addAction(openFileAction);
    this->addToolBar(toolBar);
}

//打开槽函数实现
void TextEditor::on_openFile_triggered()
{
    //打开文件
    //获取系统当前目录
    QString curPath = QDir::currentPath();
    //对话框标题
    QString dlgTitle = "打开一个文件";
    //文件过滤器
    QString filter = "程序文件(*.h *.cpp);;文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);

    if(aFileName.isEmpty())
        return;

    QFile aFile(aFileName);

    //文件不存在
    if(!aFile.exists())
        return;
    if(!aFile.open(QIODevice::ReadOnly|QIODevice::Text))
        return;

    QTextStream aStream(&aFile);

    editText->setPlainText(aStream.readAll());
    aFile.close();

}

//新建槽函数实现
void TextEditor::on_newFile_triggered()
{

}
