#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H
#include "ball.h"
#include <QWidget>
#include <QList>
#include <QMouseEvent>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
class MainWindow;
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

    void changeTimeLabel2(int count);
    void changeBlueLifeLabel2(int life);
    void changeGreenLifeLabel2(int life);
protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
private:  
    QPoint p1,p2;
    bool drawsignal;

    MainWindow *pmain;  //指向主窗口的指针
    QLabel *timeLabel,*blueLifeLabel,*greenLifeLabel,*theWinnerLabel;//都是指针.
    QLabel *timeLabel2,*blueLifeLabel2,*greenLifeLabel2,*theWinnerLabel2;
    QPushButton *stopButton;//控制暂停和重新启动.

    QTimer *time;
signals:

public slots:
    //void repeatPress();
    void stopBall();
    void timeDisplay();
};

#endif // RIGHTWIDGET_H
