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
             QColor c);//增加完整构造函数
    void setRectangle(const QRect& rect){
        this->rect=rect;
    }
    void draw(QPainter *p);  //绘制小球,传给它一个画布，将来不用QT组件，一致性会更好。

    void checkCollision(Ball &b);
    void move(); //在指定的方向上移动 1 步
    void checkBoundary();


private:
    double x,y;  //小球的中心为位置
    double radius;  //小球半径
    double speed;  //小球移动速度
    double angle;  //小球移动角度
    QColor color;   //小球填充颜色
    QRect rect;    //用于检测的窗口矩形区域,这里把它作为了数据成员.将来最好做成传参的形式。


};

#endif // BALL_H
