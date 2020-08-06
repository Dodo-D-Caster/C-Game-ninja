#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H
#include "ball.h"
#include <QWidget>
#include <QList>
#include <QMouseEvent>
class RightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);//重载虚函数
    void updateBalls();  //定义移动小球的接口
    void addBall(const Ball& b);  //添加小球的接口

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:  
    //Ball ball;//定义小球,单个小球
    QList<Ball> balls;//多个小球
    QPoint p1,p2;
    bool drawsignal;
signals:

public slots:
};

#endif // RIGHTWIDGET_H
