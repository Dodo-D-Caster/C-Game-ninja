//#include "leftwidget.h"
//#include <QGridLayout>
//#include <QPalette>
//#include <QEvent>
//#include <QPainter>
//#include <QString>
//#include "mainwindow.h"
//#include "rightwidget.h"
//LeftWidget::LeftWidget(QWidget *parent) : QWidget(parent)
//{
//    pmain=(MainWindow *)parent;
//    RightWidget p(this);
//    p.updateBalls();
//    //pright=(RightWidget *)parent;
//    //pmain->StopTimer();
//    timeLabel=new QLabel(this);
//    timeLabel->setText(tr("游戏时长:"));
//    timeLabel2=new QLabel(this);
//    timeLabel2->setText(QString::number(pmain->timeDisplay()));
//    blueLifeLabel=new QLabel(this);
//    blueLifeLabel->setText(tr("小蓝生命:"));
//    blueLifeLabel2=new QLabel(this);
//    blueLifeLabel2->setText(QString::number(p.BlueLife));
//    greenLifeLabel=new QLabel(this);
//    greenLifeLabel->setText(tr("小绿生命:"));
//    greenLifeLabel2=new QLabel(this);
//    greenLifeLabel2->setText(QString::number(p.GreenLife));
//    theWinnerLabel=new QLabel(this);
//    theWinnerLabel->setText(tr("对战状态："));
//    theWinnerLabel2=new QLabel(this);

//    if(p.theGreenWin()||p.BlueLife==0){
//        theWinnerLabel2->setText(tr("小绿获胜！"));
//    }
//    else if(p.theBlueWin()||p.GreenLife==0){
//        theWinnerLabel2->setText(tr("小蓝获胜！"));
//    }
//    else theWinnerLabel2->setText(tr("对战中..."));

//    stopButton=new QPushButton(tr("开始游戏"),this);

//    QFont font;
//    font.setPointSize(14);//字体大小
//    font.setFamily("方正舒体");
//    timeLabel->setFont(font);
//    blueLifeLabel->setFont(font);
//    greenLifeLabel->setFont(font);
//    theWinnerLabel->setFont(font);
//    timeLabel2->setFont(font);
//    blueLifeLabel2->setFont(font);
//    greenLifeLabel2->setFont(font);
//    theWinnerLabel2->setFont(font);
//    timeLabel->setStyleSheet("color:red;");
//    blueLifeLabel->setStyleSheet("color:red;");
//    greenLifeLabel->setStyleSheet("color:red;");
//    theWinnerLabel->setStyleSheet("color:red;");
//    timeLabel2->setStyleSheet("color:red;");
//    blueLifeLabel2->setStyleSheet("color:red;");
//    greenLifeLabel2->setStyleSheet("color:red;");
//    theWinnerLabel2->setStyleSheet("color:red;");
//    //timeLabel->setStyleSheet("label.gif");

//    QGridLayout *mainLayout=new QGridLayout(this);
//    mainLayout->addWidget(timeLabel,0,0);
//    mainLayout->addWidget(timeLabel2,0,1);
//    mainLayout->addWidget(blueLifeLabel,1,0);
//    mainLayout->addWidget(blueLifeLabel2,1,1);
//    mainLayout->addWidget(greenLifeLabel,2,0);
//    mainLayout->addWidget(greenLifeLabel2,2,1);
//    mainLayout->addWidget(theWinnerLabel,3,0);
//    mainLayout->addWidget(theWinnerLabel2,3,1);
//    mainLayout->addWidget(stopButton,4,0);
//    setLayout(mainLayout);

//    connect(stopButton,SIGNAL(clicked()),this,SLOT(stopBall()));
//    //实现按钮点击事件的槽方法
//}
//void LeftWidget::stopBall(){
//    if(stopButton->text()==tr("开始游戏")){
//        pmain->resumeTimer();
//        stopButton->setText(tr("暂停"));
//     }
//    else if(stopButton->text()==tr("暂停")){
//        pmain->StopTimer();
//        stopButton->setText(tr("开始"));
//    }
//    else{
//        pmain->resumeTimer();
//        stopButton->setText(tr("暂停"));
//    }
//}//实现按钮点击事件的槽方法

//void LeftWidget::changeTimeLabel2(int count){
//    timeLabel2->setText(QString::number(count));
//}
//void LeftWidget::changeBlueLifeLabel2(int life){
//    blueLifeLabel2->setText(QString::number(life));
//}
//void LeftWidget::changeGreenLifeLabel2(int life){
//    greenLifeLabel2->setText(QString::number(life));
//}

////void LeftWidget::changetheWinnerLabel2(Ball &b, Ball &p){
////    if(p.theGreenWin()||p.BlueLife==0){
////        theWinnerLabel2->setText(tr("小绿获胜！"));
////    }
////    else if(p.theBlueWin()||p.GreenLife==0){
////        theWinnerLabel2->setText(tr("小蓝获胜！"));
////    }
////    else theWinnerLabel2->setText(tr("对战中..."));
////}

////bool LeftWidget::theBlueWin(){
////    RightWidget p(this);
////    if(p.theBlue.isItWin())
////        return 1;
////    else return 0;
////}
////bool LeftWidget::theGreenWin(){
////    RightWidget p(this);
////    if(p.theGreen.isItWin())
////        return 1;
////    else return 0;
////}
