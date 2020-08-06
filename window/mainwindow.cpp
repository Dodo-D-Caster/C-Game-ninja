#include <QDesktopWidget>
#include <QApplication>
#include "mainwindow.h"
#include <QStatusBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setWindowTitle(tr("简单窗口程序"));
    centerWidget=new CenterWidget(this);
    setCentralWidget(centerWidget);

    QDesktopWidget* desktop = QApplication::desktop(); //调整主窗体的大小
    resize(desktop->width()/2,desktop->height()/2);
    move((desktop->width() - this->width())/2,
     (desktop->height() - this->height())/2);

    fileMenu=menuBar()->addMenu(tr("文件"));
    exitAction=new QAction(tr("退出"),this);
    exitAction->setShortcut(tr("Ctrl+X"));
    exitAction->setStatusTip(tr("退出程序"));
    fileMenu->addAction(exitAction);

    lineAction=new QAction(QIcon("line.gif"),tr("线条"),this);
    lineAction->setShortcut(tr("Ctrl+L"));
    lineAction->setStatusTip(tr("绘制线条"));

    ellipseAction=new QAction(QIcon("ellipse.gif"),tr("椭圆"),this);
    ellipseAction->setShortcut(tr("Ctrl+E"));
    ellipseAction->setStatusTip(tr("绘制椭圆"));

    rectangleAction=new QAction(QIcon("rectangle.gif"),tr("矩形"),this);
    rectangleAction->setShortcut(tr("Ctrl+R"));
    rectangleAction->setStatusTip(tr("绘制矩形"));

    drawMenu=this->menuBar()->addMenu(tr("绘图"));
    drawMenu->addAction(lineAction);
    drawMenu->addAction(ellipseAction);
    drawMenu->addAction(rectangleAction);

    statusBar()->show();

    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(lineAction,SIGNAL(triggered()),this,SLOT(line()));
    connect(ellipseAction,SIGNAL(triggered()),this,SLOT(ellipse()));
    connect(rectangleAction,SIGNAL(triggered()),this,SLOT(rectangle()));
}
MainWindow::~MainWindow()
{

}
void MainWindow::line(){
    centerWidget->setDrawType(0);
    centerWidget->update();
}
void MainWindow::ellipse(){
    centerWidget->setDrawType(1);
    centerWidget->update();
}
void MainWindow::rectangle(){
    centerWidget->setDrawType(2);
    centerWidget->update();
}
