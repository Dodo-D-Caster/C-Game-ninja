#include "rightwidget.h"
#include <cmath>
#include <QPainter>
#include <QKeyEvent>
#include <QGridLayout>
#include <QProcess>
#include <QApplication>
#include "paintlabel.h"
#include "leftwidget.h"
#include "mainwindow.h"
RightWidget::RightWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1700,400);//初始化
    this->grabKeyboard();
    balls.clear();
    theBlue=Ball(50,100,20,0,0,Qt::blue);
    theGreen=Ball(50,300,20,0,0,Qt::green);

    addBall (Ball(100,200,20,1,0,Qt::red));
    addBall (Ball(250,200,22,2,180,Qt::red));
    addBall (Ball(400,200,24,3,0,Qt::red));
    addBall (Ball(550,200,26,4,180,Qt::red));
    addBall (Ball(700,200,28,5,0,Qt::red));
    addBall (Ball(850,200,30,6,180,Qt::red));
    addBall (Ball(1000,200,32,7,0,Qt::red));
    addBall (Ball(1150,200,34,7.5,180,Qt::red));
    addBall (Ball(1300,200,36,8.0,0,Qt::red));
    addBall (Ball(1450,200,38,8.5,180,Qt::red));
    addBall (Ball(1600,200,40,9.0,0,Qt::red));

//    QPainter painter(this);
//    drawImage

    time=new QTimer(this);//运行时间
    connect(time,SIGNAL(timeout()),this,SLOT(timeDisplay()));
    time->start(1000);

    pmain=(MainWindow *)parent;//各个标签
    timeLabel=new QLabel(this);
    timeLabel->setText(tr("运行时长:"));
    timeLabel2=new QLabel(this);
    timeLabel2->setText("0");
    blueLifeLabel=new QLabel(this);
    blueLifeLabel->setText(tr("小红生命:"));
    blueLifeLabel2=new QLabel(this);
    blueLifeLabel2->setText(QString::number(BlueLife));
    greenLifeLabel=new QLabel(this);
    greenLifeLabel->setText(tr("小灰生命:"));
    greenLifeLabel2=new QLabel(this);
    greenLifeLabel2->setText(QString::number(GreenLife));
    theWinnerLabel=new QLabel(this);
    theWinnerLabel->setText(tr("对战状态："));
    theWinnerLabel2=new QLabel(this);
    theWinnerLabel2->setText(tr("对战中..."));
    stopButton=new QPushButton(tr("开始游戏"),this);

    QFont font;//调字体+颜色
    font.setPointSize(14);
    font.setFamily("方正舒体");
    timeLabel->setFont(font);
    blueLifeLabel->setFont(font);
    greenLifeLabel->setFont(font);
    theWinnerLabel->setFont(font);
    timeLabel2->setFont(font);
    blueLifeLabel2->setFont(font);
    greenLifeLabel2->setFont(font);
    theWinnerLabel2->setFont(font);
    timeLabel->setStyleSheet("color:red;");
    blueLifeLabel->setStyleSheet("color:red;");
    greenLifeLabel->setStyleSheet("color:red;");
    theWinnerLabel->setStyleSheet("color:red;");
    timeLabel2->setStyleSheet("color:red;");
    blueLifeLabel2->setStyleSheet("color:red;");
    greenLifeLabel2->setStyleSheet("color:red;");
    theWinnerLabel2->setStyleSheet("color:red;");

    QGridLayout *mainLayout=new QGridLayout(this);//各标签位置
    mainLayout->addWidget(timeLabel,0,0);
    mainLayout->addWidget(timeLabel2,0,1);
    mainLayout->addWidget(blueLifeLabel,0,2);
    mainLayout->addWidget(blueLifeLabel2,0,3);
    mainLayout->addWidget(greenLifeLabel,0,4);
    mainLayout->addWidget(greenLifeLabel2,0,5);
    mainLayout->addWidget(theWinnerLabel,0,6);
    mainLayout->addWidget(theWinnerLabel2,0,7);
    mainLayout->addWidget(stopButton,8,8);
    setLayout(mainLayout);

    connect(stopButton,SIGNAL(clicked()),this,SLOT(stopBall()));

}

void RightWidget::paintEvent(QPaintEvent *)//橡皮线等等的绘制
{
    QPainter p(this);
    QImage red("red.png");
    QImage green("green.png");
    //theBlue.draw(&p);
    //theGreen.draw(&p);
    theBlue.drawImage(&p,red);
    theGreen.drawImage(&p,green);
    //QImage image("beibiao.png");
    for(auto& b:balls){
        //b.draw(&p);
        QImage d("feibiao.png");
        b.drawImage(&p,d);

    }
    QPen pen(Qt::black,2,Qt::DashDotLine);
    p.setPen(pen);
    if(drawsignal)p.drawLine(p1,p2);

}

void RightWidget::updateBalls()//刷新位置并作出判断
{
    theBlue.setRectangle(this->geometry());
    theBlue.move();
    theGreen.setRectangle(this->geometry());
    theGreen.move();
    for(auto &b:balls){
            b.setRectangle(this->geometry());
            b.move();
    }
    int j;
    for(j=0;j<balls.size();++j)
        if(theBlue.collision(balls[j])==1){
            //theBlue.checkCollision(balls[j]);
            theBlue=Ball(50,100,20,0,0,Qt::blue);
            BlueLife--;
            changeBlueLifeLabel2(BlueLife);
            }
    for(j=0;j<balls.size();++j)
        if(theGreen.collision(balls[j])==1){
            //theBlue.checkCollision(balls[j]);
            theGreen=Ball(50,300,20,0,0,Qt::green);
            GreenLife--;
            changeGreenLifeLabel2(GreenLife);
            }
    theBlue.checkCollision(theGreen);
    if(theGreenWin()||(BlueLife<=0&&BlueLife<GreenLife)){
        theWinnerLabel2->setText(tr("小灰の优势！"));
    }
    else if(theBlueWin()||(GreenLife<=0&&BlueLife>GreenLife)){
        theWinnerLabel2->setText(tr("小红の优势！"));
    }
    else theWinnerLabel2->setText(tr("对战中..."));
    update(); //更新窗口显示，重绘小球
}

void RightWidget::addBall(const Ball &b){//加小球
    balls.append(b);
}

void RightWidget::mousePressEvent(QMouseEvent *e){//鼠标操作
    p1.setX(int(theGreen.getX()));
    p1.setY(int(theGreen.getY()));
}
void RightWidget::mouseMoveEvent(QMouseEvent *e){
    p2.setX(e->x());
    p2.setY(e->y());
    drawsignal=1;
}
void RightWidget::mouseReleaseEvent(QMouseEvent *e){
    p2.setX(e->x());
    p2.setY(e->y());
    double disx,disy;
    disx=p2.x()-p1.x();
    disy=p2.y()-p1.y();
    double angle,speed;
    double PI=3.1415;
    if(disy<0&&disx>0)
        angle=-(90-atan2(-disy,disx)*180/PI);
    else if(disy<0&&disx<0)
        angle=-(270+atan2(-disy,-disx)*180/PI);
    else if(disy>0&&disx<0)
        angle=-(270-atan2(disy,-disx)*180/PI);
    else
        angle=-(90+atan2(disy,disx)*180/PI);
    double dis;
    dis=sqrt(disx*disx+disy*disy);
    if(dis<10) dis=0;
    speed=0.02*(dis);
    if(speed>5) speed=5;
    theGreen=Ball(p1.x(),p1.y(),20,speed,180+angle,Qt::green);
    drawsignal=0;
}

void RightWidget::keyPressEvent(QKeyEvent *e){//键盘操作

    if(e->key()==Qt::Key_W){     //上 w 180 87
        theBlue.setSpeed(4);
        theBlue.setAngle(180);
    }
    if(e->key()==Qt::Key_A){     //左 a -90 65
        theBlue.setSpeed(4);
        theBlue.setAngle(-90);
    }
    if(e->key()==Qt::Key_D){     //右 d 90 68
        theBlue.setSpeed(4);
        theBlue.setAngle(90);
    }
    if(e->key()==Qt::Key_S){     //下 s 0 83
        theBlue.setSpeed(4);
        theBlue.setAngle(0);
    }
    if(e->key()==Qt::Key_R){
        qApp->closeAllWindows();
        QProcess::startDetached(QApplication::applicationFilePath());
    }
}
void RightWidget::keyReleaseEvent(QKeyEvent *e){
    if(e->key()==Qt::Key_W){     //上 w 180
        theBlue.setSpeed(0);
    }
    if(e->key()==Qt::Key_A){     //左 a -90
        theBlue.setSpeed(0);
    }
    if(e->key()==Qt::Key_D){     //右 d 90
        theBlue.setSpeed(0);
    }
    if(e->key()==Qt::Key_S){     //下 s 0
        theBlue.setSpeed(0);
    }
}

bool RightWidget::theBlueWin(){//判断输赢
    if(theBlue.isItWin())
        return 1;
    else return 0;
}
bool RightWidget::theGreenWin(){
    if(theGreen.isItWin())
        return 1;
    else return 0;
}

void RightWidget::changeTimeLabel2(int count){//改变标签值
    timeLabel2->setText(QString::number(count));
}
void RightWidget::changeBlueLifeLabel2(int life){
    blueLifeLabel2->setText(QString::number(life));
}
void RightWidget::changeGreenLifeLabel2(int life){
    greenLifeLabel2->setText(QString::number(life));
}

void RightWidget::stopBall(){//开始与暂停键-槽方法
    if(stopButton->text()==tr("开始游戏")){
        pmain->resumeTimer();
        stopButton->setText(tr("暂停"));
     }
    else if(stopButton->text()==tr("暂停")){
        pmain->StopTimer();
        stopButton->setText(tr("开始"));
    }
    else{
        pmain->resumeTimer();
        stopButton->setText(tr("暂停"));
    }
}

void RightWidget::timeDisplay(){//显示运行时间-槽方法
    static int count = -1;
    count++;
    changeTimeLabel2(count);
}
