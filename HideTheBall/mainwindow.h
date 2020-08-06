#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include <QSplitter>
#include "leftwidget.h"
#include "rightwidget.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //定时器常常定义在mainwindows中。
    RightWidget* getRightWidget(){return right;}//主窗口类中封装获取右侧窗口的接口(让右侧窗口的指针返回来调用）
    void StopTimer();  //停止定时器的接口,保持leftwidget的简洁。
    void resumeTimer();  //重启定时器的接口

protected slots:
    void timeToShow();    //QTimer中很重要的功能为start,定时器事件对应的槽方法
private:
    //LeftWidget *left;//保存左右窗口的指针
    RightWidget *right;
    QSplitter *splitter;
    QTimer *timer;    //定时器对象

    void paintEvent(QPaintEvent* e);
};

#endif // MAINWINDOW_H
