#include "leftwidget.h"
#include <QGridLayout>
#include <QPalette>
#include <QEvent>
#include <QPainter>
#include <QString>
#include "mainwindow.h"

LeftWidget::LeftWidget(QWidget *parent) : QWidget(parent)
{
    pmain=(MainWindow *)parent;
    xLabel=new QLabel(this);
    xLabel->setText(tr("x 坐标:"));
    yLabel=new QLabel(this);
    yLabel->setText(tr("y 坐标:"));
    radiusLabel=new QLabel(this);
    radiusLabel->setText(tr("半径:"));
    speedLabel=new QLabel(this);
    speedLabel->setText(tr("速度:"));
    angleLabel=new QLabel(this);
    angleLabel->setText(tr("角度:"));
    colorLabel=new QLabel(this);
    colorLabel->setText(tr("颜色:"));

    xEdit=new QLineEdit("100",this);
    yEdit=new QLineEdit("50",this);
    radiusEdit=new QLineEdit("10",this);
    speedEdit=new QLineEdit("5",this);
    angleEdit=new QLineEdit("40",this);

    addButton=new QPushButton(tr("添加"),this);
    stopButton=new QPushButton(tr("暂停"),this);

    colorPreview=new PaintLabel(this);//自定义类
    colorPreview->setText(tr("       "));  //初始字符串确定控件大小

    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->addWidget(xLabel,0,0);
    mainLayout->addWidget(xEdit,0,1);
    mainLayout->addWidget(yLabel,1,0);
    mainLayout->addWidget(yEdit,1,1);
    mainLayout->addWidget(radiusLabel,2,0);
    mainLayout->addWidget(radiusEdit,2,1);
    mainLayout->addWidget(speedLabel,3,0);
    mainLayout->addWidget(speedEdit,3,1);
    mainLayout->addWidget(angleLabel,4,0);
    mainLayout->addWidget(angleEdit,4,1);
    mainLayout->addWidget(colorLabel,5,0);
    mainLayout->addWidget(colorPreview,5,1);
    mainLayout->addWidget(addButton,6,0);
    mainLayout->addWidget(stopButton,6,1);
    setLayout(mainLayout);

    connect(addButton,SIGNAL(clicked()),this,SLOT(addBall()));
    connect(stopButton,SIGNAL(clicked()),this,SLOT(stopBall()));
    //实现按钮点击事件的槽方法
}
void LeftWidget::addBall(){
    RightWidget *right=pmain->getRightWidget();
 //pmain 是指向主窗口的指针，通过其接口 getRightWidget 获得
 //右侧窗口指针，再调用 right 的addBall 接口添加小球
    double x,y;
    double radius,angle,speed;
    QColor fillColor;
    bool ok;
    x=xEdit->text().toDouble(&ok);
    y=yEdit->text().toDouble(&ok);
    radius=radiusEdit->text().toDouble(&ok);
    speed=speedEdit->text().toDouble(&ok);
    angle=angleEdit->text().toDouble(&ok);
    fillColor=colorPreview->getFillColor();
    right->addBall(Ball(x,y,radius,speed,angle,fillColor));//迂回的办法.
}
void LeftWidget::stopBall(){
    if(stopButton->text()==tr("暂停")){
        pmain->StopTimer();
        stopButton->setText(tr("开始"));
    }
    else{
        pmain->resumeTimer();
        stopButton->setText(tr("暂停"));
    }
}//实现按钮点击事件的槽方法
