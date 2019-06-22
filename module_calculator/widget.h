#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initUI();
private:

    //计算器输入文本框的定义
    QLineEdit *lineEditCalculate;
    //计算器输出框的定义
    QLineEdit *lineEditAnswer;

    //计算器按钮
    //第一行按钮
    QPushButton *btnNumberSeven;
    QPushButton *btnNumberEight;
    QPushButton *btnNumberNine;
    QPushButton *btnOperatorAdd;
    QPushButton *btnOperatorLeftBracket;

    //第二行按钮
    QPushButton *btnNumberFour;
    QPushButton *btnNumberFive;
    QPushButton *btnNumberSix;
    QPushButton *btnOperatorSubtract;
    QPushButton *btnOperatorRightBracket;

    //第三行按钮
    QPushButton *btnNumberOne;
    QPushButton *btnNumberTwo;
    QPushButton *btnNumberThree;
    QPushButton *btnOperatorMultiply;
    QPushButton *btnBackspace;

    //第四行按钮
    QPushButton *btnNumberZero;
    QPushButton *btnRadixPoint;
    QPushButton *btnOperatorEqual;
    QPushButton *btnOperatorDivide;
    QPushButton *btnClear;
private slots:
    void on_btnCalculator_clicked();

};

#endif // WIDGET_H
