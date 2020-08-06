#include "mainwindow.h"
//实例化
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("小蓝小绿的生存大冒险（小蓝请用wasd控制 小绿请用鼠标控制）");//标题
    splitter=new QSplitter(Qt::Horizontal,this);  //水平切分,水平分割，将来可以嵌套分割。
    left=new LeftWidget(this);//实例化左右窗体
    right=new RightWidget(this);

    splitter->addWidget(left);//把窗体添加到分割中
    splitter->addWidget(right);

    splitter->setStretchFactor(0,1);  //设置切分的默认比例，1:4
    splitter->setStretchFactor(1,4);  //第一个窗格比例是1，第二个是4.
    splitter->setStyleSheet("QSplitter::handle { background-color: gray }"); //setStyleSheet,类似网页样式表，不深究。把分割器背景颜色设置为灰色.
    splitter->setHandleWidth(10);  //设置分割条的大小和样式

    this->setCentralWidget(splitter);

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeToShow()));//绑定定时器中的timeout事件到槽方法timeToShow()
    //time->setInterval(1000);
    timer->stop();
    time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(timeDisplay()));
    time->start(1000);//真正触发定时器，1000ms触发一次，每次触发会产生timeout消息，再由timeToShow()处理.

}

MainWindow::~MainWindow()
{

}
void MainWindow::timeToShow(){//处理定时器
    right->updateBalls();//调用rightwidget中定义的更新球。各自有各自的职责。
}
int MainWindow::timeDisplay(){
    static int count = -1;
    count++;
    return count;
}
void MainWindow::StopTimer(){
    timer->stop();
}
void MainWindow::resumeTimer(){
    timer->start(100);
}
void MainWindow::paintEvent(QPaintEvent* e){
    QPixmap  pixmap = QPixmap("background.jpg").scaled(this->size());//pixmap对象
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);//绘制
}
