#include "rightwidget.h"
#include <cmath>
#include <QPainter>
#include "paintlabel.h"
RightWidget::RightWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(400,200);
    balls.clear(); //清空后手工添加 3 个小球，用于测试
    addBall(Ball(30,20,10,10,49,Qt::red));
    addBall (Ball(56,200,10,4,39,Qt::blue));
    addBall (Ball(80,100,10,7,69,Qt::yellow));
}
void RightWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);//需要在不同类之间传参，不能在ball里面定义
   // ball.draw(&p);//传p给draw，小球在draw中完成自我绘制

    for(auto& b:balls)
            b.draw(&p);//C++11特性，循环，对容器中对每个元素进行快速遍历.
    QPen pen(Qt::black,2,Qt::DashDotLine);
    p.setPen(pen);
    if(drawsignal)p.drawLine(p1,p2);
}
void RightWidget::updateBalls()  //封装的控制小球移动的接口
{
   // ball.setRectangle(this->geometry());
   // ball.move();//自己移动一次.
    for(auto &b:balls){
            b.setRectangle(this->geometry());
            b.move();
        } //先移动小球，处理与边框的碰撞，再处理小球间碰撞
    //C++11特性，循环，对容器中对每个元素进行快速遍历.
    int i,j;
       for(i=0;i<balls.size()-1;++i){
           for(j=i+1;j<balls.size();++j)
               balls[i].checkCollision(balls[j]);
       }//集成碰撞检测方法
    update();    //更新窗口显示，重绘小球
}
void RightWidget::addBall(const Ball &b){
    balls.append(b);
}//预留给别的接口
void RightWidget::mousePressEvent(QMouseEvent *e){
    p1.setX(e->x());
    p1.setY(e->y());
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
    double angle,speed,radius;
    radius=10;
    double PI=3.1415;
    if(disy<0&&disx>0)
        angle=-(90-atan2(-disy,disx)*180/PI);
    else if(disy<0&&disx<0)
        angle=-(270+atan2(-disy,-disx)*180/PI);
    else if(disy>0&&disx<0)
        angle=-(270-atan2(disy,-disx)*180/PI);
    else
        angle=-(90+atan2(disy,disx)*180/PI);
    speed=(sqrt(disx*disx+disy*disy));
    QColor color;
    PaintLabel p(this);
    color=p.getFillColor();
    addBall(Ball(p1.x(),p1.y(),radius,speed,180+angle,color));
    drawsignal=0;
}
