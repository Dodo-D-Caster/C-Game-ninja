#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H
#include "ball.h"
#include <QWidget>
#include <QList>
class RightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);//重载虚函数
    void updateBalls();  //定义移动小球的接口
    void addBall(const Ball& b);  //添加小球的接口
private:
    //Ball ball;//定义小球,单个小球
    QList<Ball> balls;//多个小球
signals:

public slots:
};

#endif // RIGHTWIDGET_H
