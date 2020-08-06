#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H
#include "ball.h"
#include <QWidget>
#include <QList>
#include <QMouseEvent>
#include <QLabel>
#include <QTimer>
class LeftWidget;
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
    Ball theBlue;
    Ball theGreen;
    QList<Ball> balls;//多个小球
    bool theBlueWin();
    bool theGreenWin();
    int BlueLife=10;
    int GreenLife=10;
protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
private:
    QPoint p1,p2;
    bool drawsignal;
    LeftWidget *pleft;
signals:

public slots:
    //void repeatPress();
};

#endif // RIGHTWIDGET_H
