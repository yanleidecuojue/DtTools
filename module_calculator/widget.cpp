#include "widget.h"
#include <QGridLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    initUI();

    //计算器按键信号与槽的连接
    //第一行按钮信号与槽连接
    connect(btnNumberSeven,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnNumberEight,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnNumberNine,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnOperatorAdd,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnOperatorLeftBracket,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    //第二行按钮信号与槽连接
    connect(btnNumberFour,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnNumberFive,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnNumberSix,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnOperatorSubtract,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnOperatorRightBracket,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    //第三行按钮信号与槽连接
    connect(btnNumberOne,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnNumberTwo,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnNumberThree,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnOperatorMultiply,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnBackspace,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    //第四行按钮信号与槽连接
    connect(btnNumberZero,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnRadixPoint,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnOperatorEqual,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnOperatorDivide,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));
    connect(btnClear,SIGNAL(clicked()),this,SLOT(on_btnCalculator_clicked()));

    //设置显示框体的大小
    setMinimumSize(600,400);
    setMaximumSize(800,800);
}

Widget::~Widget()
{

}

//UI创建与初始化
void Widget::initUI()
{
    //输入框
    lineEditCalculate = new QLineEdit();
    lineEditCalculate->setReadOnly(true);
    lineEditCalculate->setAlignment(Qt::AlignRight);


    //输出框
    lineEditAnswer = new QLineEdit();
    lineEditAnswer->setReadOnly(true);

    //第一行按钮
    btnNumberSeven = new QPushButton(tr("7"));
    btnNumberEight = new QPushButton(tr("8"));
    btnNumberNine = new QPushButton(tr("9"));
    btnOperatorAdd = new QPushButton(tr("+"));
    btnOperatorLeftBracket = new QPushButton(tr("("));

    //第二行按钮
    btnNumberFour = new QPushButton(tr("4"));
    btnNumberFive = new QPushButton(tr("5"));
    btnNumberSix = new QPushButton(tr("6"));
    btnOperatorSubtract = new QPushButton(tr("-"));
    btnOperatorRightBracket = new QPushButton(tr(")"));

    //第三行按钮
    btnNumberOne = new QPushButton(tr("1"));
    btnNumberTwo = new QPushButton(tr("2"));
    btnNumberThree = new QPushButton(tr("3"));
    btnOperatorMultiply = new QPushButton(tr("*"));
    btnBackspace = new QPushButton(tr("<-"));

    //第四行代码
    btnNumberZero = new QPushButton(tr("0"));
    btnRadixPoint = new QPushButton(tr("."));
    btnOperatorEqual = new QPushButton(tr("="));
    btnOperatorDivide = new QPushButton(tr("/"));
    btnClear = new QPushButton(tr("C"));


    QGridLayout *GLay1 = new QGridLayout;

    //添加第一行布局
    GLay1->addWidget(btnNumberSeven,0,0);
    GLay1->addWidget(btnNumberEight,0,1);
    GLay1->addWidget(btnNumberNine,0,2);
    GLay1->addWidget(btnOperatorAdd,0,3);
    GLay1->addWidget(btnOperatorLeftBracket,0,4);

    //添加第二行布局
    GLay1->addWidget(btnNumberFour,1,0);
    GLay1->addWidget(btnNumberFive,1,1);
    GLay1->addWidget(btnNumberSix,1,2);
    GLay1->addWidget(btnOperatorSubtract,1,3);
    GLay1->addWidget(btnOperatorRightBracket,1,4);

    //添加第三行布局
    GLay1->addWidget(btnNumberOne,2,0);
    GLay1->addWidget(btnNumberTwo,2,1);
    GLay1->addWidget(btnNumberThree,2,2);
    GLay1->addWidget(btnOperatorMultiply,2,3);
    GLay1->addWidget(btnBackspace,2,4);
    //添加第四行布局
    GLay1->addWidget(btnNumberZero,3,0);
    GLay1->addWidget(btnRadixPoint,3,1);
    GLay1->addWidget(btnOperatorEqual,3,2);
    GLay1->addWidget(btnOperatorDivide,3,3);
    GLay1->addWidget(btnClear,3,4);

    GLay1->setSpacing(15);
    GLay1->setVerticalSpacing(20);

    //竖直主布局
    QVBoxLayout *VLay1 = new QVBoxLayout;
    VLay1->addWidget(lineEditCalculate);
    VLay1->addStretch();
    VLay1->addWidget(lineEditAnswer);
    VLay1->addStretch();
    VLay1->addLayout(GLay1);
    setLayout(VLay1);
}


void Widget::on_btnCalculator_clicked()
{

    QPushButton *btnSender = dynamic_cast<QPushButton*>(sender());
    QString txtCalculate = btnSender->text();
    lineEditCalculate->setText(txtCalculate);



}

