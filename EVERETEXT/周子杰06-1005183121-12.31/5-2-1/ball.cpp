#include "ball.h"
#include <cmath>
Ball::Ball():Ball(40,100,10,10,45,Qt::red)
{   //通过委托构造实现缺省构造函数
}
Ball::Ball(double xpos,double ypos,double r,double s,double a,QColor c)
    :x(xpos),y(ypos),radius(r),speed(s),angle(a),color(c)
{
}
void Ball::draw(QPainter *p)
{
    QPen pen(color,1,Qt::SolidLine);
    QBrush brush(color);
    p->setPen(pen);
    p->setBrush(brush);
    QRect r(x-radius,y-radius,radius*2,radius*2);//定义坐标,左上角坐标+矩形长宽
    p->drawEllipse(r);
}

void Ball::move(){
    double dx,dy;
    const double PI=3.14159;
    dx=speed*std::sin(angle*PI/180);
    dy=speed*std::cos(angle*PI/180);
    x+=dx;
    y+=dy;
    checkBoundary();
    speed*=0.99;
    if(speed<0.1)
        speed=0;
}

void Ball::checkBoundary(){ //左上角（0,0）向右下递增。
    if(y+radius>rect.height()){ //超出底边界
        angle=180-angle;
        y=rect.height()-radius; //拉回来
    }
    if(y-radius<0){
        angle=180-angle;
        y=radius;//拉到相切的位置
    }
    if(x+radius>rect.width()){
        angle=-angle;
        x=rect.width()-radius;
    }
    if(x-radius<0){
        angle=-angle;
        x=radius;
    }
}

void Ball::checkCollision(Ball &b){
    double dx,dy;
    dx=x-b.x;
    dy=y-b.y;
    double dis=std::sqrt(dx*dx+dy*dy);
    if(dis<=radius+b.radius){ //碰撞后只是交换速度和角度
        speed*=0.95;
        b.speed*=0.95;
        if(speed<0.1)
            speed=0;
        if(b.speed<0.1)
            b.speed=0;
        double temp;
        temp=speed;
        speed=b.speed;
        b.speed=temp;
        temp=angle;
        angle=b.angle;
        b.angle=temp;
    }
}
