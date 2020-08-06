#ifndef PAINTLABEL_H
#define PAINTLABEL_H
#include <QLabel>
#include <QColor>
#include <QMouseEvent>
//标签控件
class PaintLabel : public QLabel
{
    Q_OBJECT
public:
    explicit PaintLabel(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void setFillColor(QColor color);
    void mousePressEvent(QMouseEvent *e);
    QColor getFillColor();
private:
    QColor fillColor;
};

#endif // PAINTLABEL_H
