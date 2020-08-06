#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QLabel *radiusLabel, *areaLabel;
    QLineEdit *radiusLineEdit;
    QPushButton *calButton;
private slots:
    void showArea();
};
#endif // DIALOG_H
