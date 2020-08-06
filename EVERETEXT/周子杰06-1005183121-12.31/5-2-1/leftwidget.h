#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H
#include "paintlabel.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class MainWindow;//一个类型（指针，对象不行）的前置声明(在别的地方有定义），通过顶层公共的副窗口，间接获得右侧窗口。不能#include“mainwindows.h",因为相互包含，递归了.

class LeftWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LeftWidget(QWidget *parent = 0);

signals:
private:
    MainWindow *pmain;  //指向主窗口的指针

    QLabel *xLabel,*yLabel,*radiusLabel,
        *speedLabel,*angleLabel,*colorLabel;//都是指针.
    QLineEdit *xEdit,*yEdit,*radiusEdit,*speedEdit,*angleEdit;

    PaintLabel *colorPreview;//增加标签的指针。预览颜色

    QPushButton *addButton,*stopButton;//控制暂停和重新启动.

public slots:
    void addBall();   //添加小球
    void stopBall();    //控制定时器的启动与暂停
    //定义按钮点击事件的槽方法,添加小球与暂停.
};

#endif // LEFTWIDGET_H
