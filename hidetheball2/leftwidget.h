#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H
#include "paintlabel.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "ball.h"
class MainWindow;//一个类型（指针，对象不行）的前置声明(在别的地方有定义），通过顶层公共的副窗口，间接获得右侧窗口。不能#include“mainwindows.h",因为相互包含，递归了.
class LeftWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LeftWidget(QWidget *parent = 0);
    void changeTimeLabel2(int count);
    void changeBlueLifeLabel2(int life);
    void changeGreenLifeLabel2(int life);
    //void changetheWinnerLabel2(Ball &b,Ball &p);
signals:
private:
    MainWindow *pmain;  //指向主窗口的指针
    QLabel *timeLabel,*blueLifeLabel,*greenLifeLabel,*theWinnerLabel;//都是指针.
    QLabel *timeLabel2,*blueLifeLabel2,*greenLifeLabel2,*theWinnerLabel2;
    QPushButton *stopButton;//控制暂停和重新启动.
public slots:
    void stopBall();
};

#endif // LEFTWIDGET_H
