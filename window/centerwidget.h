#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>
#include <QMouseEvent>
class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);
    void setDrawType(int type);

signals:
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
public slots:
private:
    QPixmap pixmap;
    QString mouseClickInfo;
    QString mousePosInfo;
    int drawType;
};

#endif // CENTERWIDGET_H
