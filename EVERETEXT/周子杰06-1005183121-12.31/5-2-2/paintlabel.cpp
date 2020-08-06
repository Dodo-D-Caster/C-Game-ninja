#include "paintlabel.h"
#include <QPainter>
#include <QWidget>
#include <QColorDialog>
PaintLabel::PaintLabel(QWidget *parent):QLabel(parent)
{
    fillColor=Qt::blue;//初始值为蓝色.
}
void PaintLabel::setFillColor(QColor color)
    {
        fillColor=color;
    }
QColor PaintLabel::getFillColor()
    {
        return fillColor;
    }
void PaintLabel::paintEvent(QPaintEvent *event)
    {
        QLabel::paintEvent(event);//调用基类
        QPainter p(this);
        QPen pen(fillColor,2,Qt::SolidLine);
        QBrush brush(fillColor);
        p.setPen(pen);
        p.setBrush(brush);
        p.drawRect(0,0,this->width(),this->height());//重载，构造一个矩形区域。
     //根据 fillColor 填充 Label 控件，实现颜色预览
    }
void PaintLabel:: mousePressEvent(QMouseEvent *e){
        QColor chooseColor=QColorDialog::getColor(fillColor);   //getColor就是弹出对话框，用户选择颜色，返回颜色
        if(chooseColor.isValid()==true)  //有效颜色，如果用户取消，则返回无效颜色值
        {
            fillColor=chooseColor;
            update();
        }
    }
