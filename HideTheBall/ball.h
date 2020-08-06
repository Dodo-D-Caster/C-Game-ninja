#ifndef BALL_H
#define BALL_H

#include <QColor>
#include <QRect>
#include <QPen>
#include <QBrush>
#include <QPainter>

class Ball
{
public:
    Ball();
    Ball(double xpos,double ypos,double r,double s,double a,
             QColor c);
    void setRectangle(const QRect& rect){
        this->rect=rect;
    }
    void draw(QPainter *p);
    void drawImage(QPainter *p,QImage b);
    void checkCollision(Ball &b);
    void move(); //在指定的方向上移动 1 步
    void checkBoundary();
    void setX(double X){this->x=X;}
    void setY(double Y){this->y=Y;}
    void setAngle(double angle){this->angle=angle;}
    void setSpeed(double speed){this->speed=speed;}
    double getX(){return x;}
    double getY(){return y;}
    double getAngle(){return angle;}
    bool collision(Ball &b);
    bool isItWin();
private:
    double x,y;  //小球的中心为位置
    double angle;  //小球移动角度
    double radius;  //小球半径
    double speed;  //小球移动速度

    QColor color;   //小球填充颜色
    QRect rect;    //用于检测的窗口矩形区域,这里把它作为了数据成员.将来最好做成传参的形式。
};

#endif // BALL_H
