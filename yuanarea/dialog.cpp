#include "dialog.h"
#include <QGridLayout>
#include <QDebug>

const static double PI = 3.1416;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    label1 = new QLabel(this);
    label1->setText("请输入圆的半径");
    lineEdit = new QLineEdit(this);
    label2 = new QLabel(this);
    button = new QPushButton(this);
    button->setText(tr("显示对应圆的面积"));
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(lineEdit,0,1);
    mainLayout->addWidget(label2,1,0);
    mainLayout->addWidget(button,1,1);
    connect(button,&QPushButton::clicked,this,&Dialog::showArea);
    connect(lineEdit,&QLineEdit::textChanged,this,&Dialog::showArea);
}

Dialog::~Dialog()
{

}
void Dialog::showArea()
{
    QString tempStr;
    QString valueStr = lineEdit->text();
    int valueInt = valueStr.toInt();
    double area = valueInt * valueInt *PI;
    label2->setText(tempStr.setNum(area));
}
