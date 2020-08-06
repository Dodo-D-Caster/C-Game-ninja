#include "rightwidget.h"
#include <cmath>
#include <QPainter>
#include <QKeyEvent>
#include <QGridLayout>
#include "paintlabel.h"
#include "leftwidget.h"
RightWidget::RightWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1200,400);
    this->grabKeyboard();
    balls.clear();
    theBlue=Ball(50,100,10,0,0,Qt::blue);
    theGreen=Ball(50,300,10,0,0,Qt::green);
    addBall (Ball(100,200,10,10,0,Qt::red));
    addBall (Ball(200,200,11,15,180,Qt::red));
    addBall (Ball(300,200,12,20,0,Qt::red));
    addBall (Ball(400,200,13,25,180,Qt::red));
    addBall (Ball(500,200,14,30,0,Qt::red));
    addBall (Ball(600,200,15,35,180,Qt::red));
    addBall (Ball(700,200,16,40,0,Qt::red));
    addBall (Ball(800,200,17,45,180,Qt::red));
    addBall (Ball(900,200,18,50,0,Qt::red));
    addBall (Ball(1000,200,19,55,180,Qt::red));
    addBall (Ball(1100,200,20,60,0,Qt::red));
}
void RightWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    theBlue.draw(&p);
    theGreen.draw(&p);
    for(auto& b:balls)
            b.draw(&p);
    QPen pen(Qt::black,2,Qt::DashDotLine);
    p.setPen(pen);
    if(drawsignal)p.drawLine(p1,p2);

}
void RightWidget::updateBalls()
{
    pleft=(LeftWidget *)this;
    //LeftWidget p(this);
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
            theBlue=Ball(50,100,10,0,0,Qt::blue);
            BlueLife--;
            pleft->changeBlueLifeLabel2(BlueLife);
            }
    for(j=0;j<balls.size();++j)
        if(theGreen.collision(balls[j])==1){
            theGreen=Ball(50,300,10,0,0,Qt::green);
            GreenLife--;

            }
    theBlue.checkCollision(theGreen);
    update(); //更新窗口显示，重绘小球
}
void RightWidget::addBall(const Ball &b){
    balls.append(b);
}//预留给别的接口
void RightWidget::mousePressEvent(QMouseEvent *e){
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
    speed=0.1*(sqrt(disx*disx+disy*disy));
    if(speed>30) speed=30;
    theGreen=Ball(p1.x(),p1.y(),10,speed,180+angle,Qt::green);
    drawsignal=0;
}

void RightWidget::keyPressEvent(QKeyEvent *e){

    if(e->key()==87){     //上 w 180
        theBlue.setSpeed(20);
        theBlue.setAngle(180);
    }
    if(e->key()==65){     //左 a -90
        theBlue.setSpeed(20);
        theBlue.setAngle(-90);
    }
    if(e->key()==68){     //右 d 90
        theBlue.setSpeed(20);
        theBlue.setAngle(90);
    }
    if(e->key()==83){     //下 s 0
        theBlue.setSpeed(20);
        theBlue.setAngle(0);
    }
}
void RightWidget::keyReleaseEvent(QKeyEvent *e){
    if(e->key()==87){     //上 w 180
        theBlue.setSpeed(0);
    }
    if(e->key()==65){     //左 a -90
        theBlue.setSpeed(0);
    }
    if(e->key()==68){     //右 d 90
        theBlue.setSpeed(0);
    }
    if(e->key()==83){     //下 s 0
        theBlue.setSpeed(0);
    }
}

bool RightWidget::theBlueWin(){
    if(theBlue.isItWin())
        return 1;
    else return 0;
}
bool RightWidget::theGreenWin(){
    if(theGreen.isItWin())
        return 1;
    else return 0;
}

//void RightWidget::keyPressEvent(QKeyEvent *e)//按键冲突处理 -失败
//{
//    pressedKeys.append(static_cast<Qt::Key>(e->key()));
//    if(!retimer->isActive()) {
//        retimer->start(300); // 重复间隔 REPEAT_RATE = 300 毫秒
//    }
//}

//void RightWidget::keyReleaseEvent(QKeyEvent *e)
//{
//    if(retimer->isActive() && pressedKeys.isEmpty()) {
//        retimer->stop();
//        repeatPress();
//    }
//    pressedKeys.clear();
//}

//void RightWidget::repeatPress(){
//    if(pressedKeys.contains(Qt::Key_W)) {
//        theBlue.setSpeed(20);
//        theBlue.setAngle(180);
//    }
//    if(pressedKeys.contains(Qt::Key_S)) {
//        theBlue.setSpeed(20);
//        theBlue.setAngle(0);
//    }
//    if(pressedKeys.contains(Qt::Key_A)) {
//        theBlue.setSpeed(20);
//        theBlue.setAngle(-90);
//    }
//    if(pressedKeys.contains(Qt::Key_D)) {
//        theBlue.setSpeed(20);
//        theBlue.setAngle(90);
//    }
//}

//int RightWidget::theBlueLife(){
//    int i;
//    for(i=0;i<balls.size();++i)
//        if(theBlue.collision(balls[i])==1)\
//            BlueLife--;
//    return BlueLife;
//}
//int RightWidget::theGreenLife(){
//    int i;
//    for(i=0;i<balls.size();++i)
//        if(theGreen.collision(balls[i])==1)\
//            GreenLife--;
//    return GreenLife;
//}
