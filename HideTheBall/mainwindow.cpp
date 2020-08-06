#include "mainwindow.h"
//实例化
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("红灰忍者の生存+对战大冒险（小红请用wasd控制 小灰请用鼠标控制 r键重启）");//标题
    splitter=new QSplitter(Qt::Horizontal,this);  //水平切分,水平分割，将来可以嵌套分割。
    right=new RightWidget(this);

    splitter->addWidget(right);
    splitter->setStyleSheet("QSplitter::handle { background-color: gray }"); //setStyleSheet,类似网页样式表，不深究。把分割器背景颜色设置为灰色.
    splitter->setHandleWidth(10);  //设置分割条的大小和样式

    this->setCentralWidget(splitter);

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeToShow()));//绑定定时器中的timeout事件到槽方法timeToShow()
    //time->setInterval(1000);
    timer->stop();
}

MainWindow::~MainWindow()
{

}

void MainWindow::timeToShow(){//处理定时器
    right->updateBalls();//调用rightwidget中定义的更新球。各自有各自的职责。
}
void MainWindow::StopTimer(){
    timer->stop();
}
void MainWindow::resumeTimer(){
    timer->start(10);
}
void MainWindow::paintEvent(QPaintEvent* e){
    QPixmap  pixmap = QPixmap("background.jpg").scaled(this->size());//pixmap对象
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);//绘制
}
